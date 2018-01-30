#include <iostream>

#include <vector>
#include <stdint.h>
#include <boost/endian/conversion.hpp>
using namespace ::boost::endian;

#if __cplusplus >= 201103L

#include <type_traits>
using std::enable_if;
using std::is_same;

#else

template<bool B, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T> { typedef T type; };

template<class T, class U>
struct is_same { enum {value=false}; };

template<class T>
struct is_same<T, T> { enum {value=true}; };

#endif


typedef uint64_t u64;
typedef uint32_t u32;
typedef int64_t  i64;
typedef int32_t  i32;
typedef float    f32;
typedef double   f64;
typedef uint16_t u16;
typedef int16_t  i16;
typedef uint8_t  u8;
typedef int8_t   i8;

struct First {
    enum {
        staticOffset = 0,
        dynamicOffset = 0,
        headerSize = 0,
        staticSize = 0
    };
};

struct __Last {
  typedef __Last F;
  typedef __Last N;
};
struct __LastRecursive {};
struct __Finish {
  typedef __Finish F;
  typedef __Finish N;
};

class SerializedData;

struct SerializedException {};
struct WrongType : SerializedException {};
struct WrongIndex : SerializedException {};
struct SecondInitialization : SerializedException {};

template <typename Field, typename Next, typename Dummy = void>
class ValueSetter;
typedef ValueSetter<__LastRecursive, SerializedData*> LastRecursive;

/////////////////////////////////////////////////////////////////////////////
/// \brief The RecordConstructor class
///
class RecordConstructor {
public:
    RecordConstructor(SerializedData* data);

    char* staticData(size_t size);
    char* dynamicData(size_t size);

    void nextDynamic();

    RecordConstructor* beginNested(u16 id,
                                 size_t staticSize,
                                 size_t headerSize);
    SerializedData* finishNested();

protected:
    SerializedData* data;
    size_t dynamicOffset;
    std::vector<size_t> staticOffset;
    std::vector<size_t> dynamicSizeOffset;
};

template <int recordId, typename self>
struct Record {
  enum { ID = recordId };

  template <typename type, typename parent>
  struct Field {
    typedef type T;
    typedef bool isField;

    enum {
      staticOffset = parent::staticOffset+parent::staticSize,
      dynamicOffset = parent::dynamicOffset + parent::headerSize,
      headerSize = T::headerSize,
      staticSize = T::staticSize
    };

    typedef parent previous;
    typedef self record;
  };
};

/////////////////////////////////////////////////////////////////////
/// \brief The SerializedData class
///
class SerializedData
{
    friend class RecordConstructor;
public:
    typedef u16 rid;
    typedef u32 hel;

    typedef void (*reader)(char* memory, size_t size, void* opt);

    SerializedData(size_t allocate);
    SerializedData(reader readdata, void* opt = 0);
    SerializedData(const char* block, size_t size);

    inline const char* data() const {
      if (block == 0) {
        return &vec[0];
      } else {
        return block;
      }
    }

    inline char* data() {
      if (block == 0) {
        return &vec[0];
      } else {
        return block;
      }
    }

    inline rid id() const {
      if (allocated == 0)
        return 0;
      return *(reinterpret_cast<const rid*>(data()));
    }

    std::size_t size() const;

    template< typename Field > typename Field::T field() const
    {
        if (id() != Field::record::ID)
          throw WrongType();

        const char* offset =
            data() + sizeof(rid);
        const char* staticData = offset + sizeof(hel) * Field::record::headerSize;
        const char* dynamicData = staticData + Field::record::staticSize;
        for (int i = Field::dynamicOffset - 1; i >= 0; --i) {
          dynamicData += little_to_native(reinterpret_cast<const hel*>(offset)[i]);
        }

        return typename Field::T(
                    staticData + Field::staticOffset,
                    dynamicData,
                    (reinterpret_cast<const hel*>(offset)[Field::dynamicOffset])
                );
    }

    static const size_t __LastType;

    static size_t headerSize(rid id);
    static size_t staticSize(rid id);

protected:
    char* block;
    size_t allocated;
    std::vector<char> vec;

    static const size_t headerSizes[];
    static const size_t staticSizes[];

    void requireSize(size_t size);
};


SerializedData::SerializedData(size_t allocate)
    : block(0), allocated(allocate), vec(allocate) {}

SerializedData::SerializedData(const char* block, size_t allocate)
    : block(const_cast<char*>(block)), allocated(allocate), vec() {}

void SerializedData::requireSize(size_t size) {
  if (block)
    throw SerializedException();
  vec.resize(size);
  allocated = size;
}

inline size_t SerializedData::headerSize(rid id) {
  if (id < 1 || id > __LastType)
    throw WrongType();
  return headerSizes[id];
}

size_t SerializedData::staticSize(SerializedData::rid id)
{
    if (id < 1 || id > __LastType)
      throw WrongType();
    return staticSizes[id];
}
std::size_t SerializedData::size() const {
  if (id() == 0)
    return 0;
  std::size_t sz =
      sizeof(rid) + headerSize(id()) * sizeof(hel) + staticSizes[id()];
  for (int i = headerSize(id()) - 1; i >= 0; --i) {
    sz += reinterpret_cast<const hel*>(data() + sizeof(rid))[i];
  }
  return sz;
}

SerializedData::SerializedData(reader readdata, void* opt)
    : block(0), allocated(sizeof(rid)), vec(allocated) {
  readdata(data(), sizeof(rid), opt);

  rid id = little_to_native(*reinterpret_cast<rid*>(data()));

  size_t hs = headerSize(id);

  allocated += hs * sizeof(hel);
  requireSize(allocated);

  hel* header = reinterpret_cast<hel*>(data() + sizeof(rid));

  readdata((char*)header, sizeof(hel) * hs, opt);
  std::size_t bulkSize = staticSizes[id];
  for (unsigned int i = 0; i < hs; ++i) {
    bulkSize += little_to_native(header[i]);
  }

  allocated += bulkSize;
  requireSize(allocated);

  readdata(data() + sizeof(rid) + sizeof(hel) * hs, bulkSize, opt);
}

RecordConstructor::RecordConstructor(SerializedData* data)
    : data(data),
      dynamicOffset(0)
{
}

char* RecordConstructor::staticData(size_t size) {
  char* ptr = data->data() + staticOffset.back();
  staticOffset.back() += size;
  return ptr;
}

char* RecordConstructor::dynamicData(size_t size) {
  data->requireSize(dynamicOffset + size);
  char* ptr = data->data() + dynamicOffset;
  dynamicOffset += size;

  for (std::vector<size_t>::iterator i = dynamicSizeOffset.begin();
       i != dynamicSizeOffset.end(); ++i) {
    *reinterpret_cast<SerializedData::hel*>(data->data() + *i) += size;
  }

  return ptr;
}

void RecordConstructor::nextDynamic() {
  *reinterpret_cast<SerializedData::hel*>(data->data() +
                                          dynamicSizeOffset.back()) =
      native_to_little(*reinterpret_cast<SerializedData::hel*>(
          data->data() + dynamicSizeOffset.back()));
  dynamicSizeOffset.back() += sizeof(SerializedData::hel);
}


RecordConstructor* RecordConstructor::beginNested(u16 id,
                                                  size_t staticSize,
                                                  size_t headerSize)
{
  size_t nestedSize =
      sizeof(id) + staticSize + headerSize * sizeof(SerializedData::hel);
  char* obj = dynamicData(nestedSize);
  *reinterpret_cast<u16*>(obj) = native_to_little(id);

  SerializedData::hel* dyn =
      reinterpret_cast<SerializedData::hel*>(obj + sizeof(SerializedData::rid));
  for (size_t j = headerSize; j > 0; --j, ++dyn)
    *dyn = 0;

  size_t hOffset = sizeof(id) + (obj - data->data());
  size_t sOffset = hOffset + headerSize * sizeof(SerializedData::hel);

  staticOffset.push_back(sOffset);
  dynamicSizeOffset.push_back(hOffset);

  return this;
}

SerializedData* RecordConstructor::finishNested() {
  nextDynamic();

  staticOffset.pop_back();
  dynamicSizeOffset.pop_back();

  SerializedData *data = this->data;
  if(staticOffset.size()==0)
  {
      delete this;
  }

  return data;
}


///////////////////////////////////////////////////////////////////////////////
/// \brief The FieldType class
///
class FieldType
{
public:
    FieldType( const char* staticData, const char* dynamicData, SerializedData::hel dynamicSize):
        staticData(staticData),
        dynamicData(dynamicData),
        dynamicSize(dynamicSize)
    {
    }

protected:
    const char *staticData;
    const char *dynamicData;
    const SerializedData::hel dynamicSize;
};


///////////////////////////////////////////////////////////////////////////////
/// \brief The Plain class
///
template <typename type>
class Plain: public FieldType {
public:
    typedef type T;

    Plain(const char *staticData, const char *dynamicData, SerializedData::hel dynamicSize):
        FieldType(staticData, dynamicData, dynamicSize){}

    operator const type() const {
        return value();
    }

    const type value() const {
        return little_to_native(*(reinterpret_cast<const type*>(staticData)));
    }

    enum {
        staticSize = sizeof(type),
        headerSize = 0
    };
};

template <typename Field, typename Next>
class ValueSetter<
        Field, Next,
        typename enable_if<is_same<typename Field::T, Plain<typename Field::T::T> >::value>::type
        //for_type<typename Field::T, Plain<typename Field::T::T> >
        >
{
public:
    typedef Field F;
    typedef Next N;

    ValueSetter<typename Next::F, typename Next::N>
    set(const typename Field::T::T value)
    {

      *(reinterpret_cast<typename Field::T::T*>(
          constructor->staticData(Field::staticSize))) = native_to_little(value);

      return ValueSetter<typename Next::F, typename Next::N>(constructor);
    }

    ValueSetter(RecordConstructor* constructor) : constructor(constructor) {}

protected:
    RecordConstructor* constructor;
};

///////////////////////////////////////////////////////////////////////////////
/// \brief The Vector class
///
template <typename type>
class Vector: public FieldType {
public:
    typedef type T;

    Vector(const char *staticData, const char *dynamicData, SerializedData::hel dynamicSize):
        FieldType(staticData, dynamicData, dynamicSize){}

    size_t size() const {
        return dynamicSize/sizeof(type);
    }

    const type get(size_t index) const {
        if(index>=size()) throw WrongIndex();
        return little_to_native(reinterpret_cast<const type*>(dynamicData)[index]);
    }

    enum {
        staticSize = 0,
        headerSize = 1
    };
};

template <typename Field, typename Next>
class ValueSetter<
        Field, Next,
        typename enable_if<is_same<typename Field::T, Vector<typename Field::T::T> >::value>::type
        //for_type<Field, Vector<typename Field::T::T> >
        >
{
public:
    typedef Field F;
    typedef Next N;

    ValueSetter<typename Next::F, typename Next::N>
    finish()
    {
        constructor->nextDynamic();
        return ValueSetter<typename Next::F, typename Next::N>(constructor);
    }

    ValueSetter<Field, Next> add(typename Field::T::T value)
    {
        *reinterpret_cast<typename Field::T::T*>(constructor->dynamicData(sizeof(typename Field::T::T))) = native_to_little(value);
        return ValueSetter<Field, Next>(constructor);
    }

    ValueSetter(RecordConstructor* constructor) : constructor(constructor) {}

protected:
    RecordConstructor* constructor;
};

///////////////////////////////////////////////////////////////////////////////
/// \brief The Plain class
///
class Any: public FieldType {
public:
    Any(const char *staticData, const char *dynamicData, SerializedData::hel dynamicSize):
        FieldType(staticData, dynamicData, dynamicSize){}


    const SerializedData* value() const
    {
        return new SerializedData(dynamicData, dynamicSize);
    }

    template< typename Field > typename Field::T field() const
    {
        return SerializedData(dynamicData, dynamicSize).field<Field>();
    }

    enum {
        staticSize = 0,
        headerSize = 1
    };
};

template <typename Field, typename Next>
class ValueSetter<
        Field, Next,
        typename enable_if<is_same<typename Field::T, Any >::value>::type
        //for_type<Field, Any >
        >
{
public:
    typedef Field F;
    typedef Next N;

    template <typename Record>
    typename Record::recursive beginRecursive()
    {
        if(lock) throw SecondInitialization();
        lock = true;
        return typename Record::recursive(
                    constructor->beginNested(
                        Record::ID,
                        Record::staticSize,
                        Record::headerSize
                        ));
    }

    ValueSetter<typename Next::F, typename Next::N> next()
    {
        if(lockNext) throw SecondInitialization();
        lockNext = true;
        constructor->nextDynamic();
        return ValueSetter<typename Next::F, typename Next::N>(constructor);
    }

    ValueSetter(RecordConstructor* constructor) : constructor(constructor), lock(false), lockNext(false) {}

protected:
    RecordConstructor* constructor;
    bool lock;
    bool lockNext;
};

///////////////////////////////////////////////////////////////////////////////
/// \brief The VectorOfAny class
///
class VectorOfAny: public FieldType {
public:
    VectorOfAny(const char *staticData, const char *dynamicData, SerializedData::hel dynamicSize):
        FieldType(staticData, dynamicData, dynamicSize){}

    const SerializedData get(size_t index) const {
        if(dynamicSize==0) throw WrongIndex();

        const char* offset = dynamicData;

        for(size_t i = index; i>0; --i)
        {
            if(offset-dynamicData + sizeof(SerializedData::rid) > dynamicSize) throw WrongIndex();
            SerializedData::rid id = little_to_native(*reinterpret_cast<const SerializedData::rid*>(offset));
            offset += sizeof(SerializedData::rid);
            const SerializedData::hel *headers = reinterpret_cast<const SerializedData::hel*>(offset);
            offset += SerializedData::headerSize(id)*sizeof(SerializedData::hel) + SerializedData::staticSize(id);
            if(offset-dynamicData >= dynamicSize) throw WrongIndex(); // @todo: actually it is broken structure, maybe throw that instead?
            for( size_t i = SerializedData::headerSize(id); i>0; --i, headers++)
            {
                offset += little_to_native(*headers);
            }
        }
        if(offset-dynamicData + sizeof(SerializedData::rid) > dynamicSize) throw WrongIndex();
        // extract size of the record

        SerializedData::rid id = little_to_native(*reinterpret_cast<const SerializedData::rid*>(offset));
        size_t size = sizeof(SerializedData::rid);
        const SerializedData::hel *headers = reinterpret_cast<const SerializedData::hel*>(offset+size);
        size += SerializedData::headerSize(id)*sizeof(SerializedData::hel) + SerializedData::staticSize(id);
        if(offset-dynamicData + size > dynamicSize) throw WrongIndex(); // @todo: actually it is broken structure, maybe throw that instead?
        for( size_t i = SerializedData::headerSize(id); i>0; --i, headers++)
        {
            size += little_to_native(*headers);
        }
        if(offset-dynamicData + size > dynamicSize) throw WrongIndex(); // @todo: actually it is broken structure, maybe throw that instead?
        return SerializedData(offset, size);
    }

    enum {
        staticSize = 0,
        headerSize = 1
    };
};

template <typename Field, typename Next>
class ValueSetter<
        Field, Next,
        typename enable_if<is_same<typename Field::T, VectorOfAny >::value>::type
        //typename for_type<Field, Plain<typename Field::T::T> >::type
        >
{
public:
    typedef Field F;
    typedef Next N;

    ValueSetter<typename Next::F, typename Next::N>
    finish()
    {
        constructor->nextDynamic();
        return ValueSetter<typename Next::F, typename Next::N>(constructor);
    }

    template <typename Record>
    typename Record::recursive add()
    {
        return typename Record::recursive(
                    constructor->beginNested(
                        Record::ID,
                        Record::staticSize,
                        Record::headerSize
                        ));
    }

    ValueSetter(RecordConstructor* constructor) : constructor(constructor) {}

protected:
    RecordConstructor* constructor;
};

/////////////////////////////////////////////////////////////////////////
///
///
template <typename Next>
class ValueSetter<__LastRecursive, Next> {
  template <typename _Field, typename _Next, typename _Dummy>
  friend class ValueSetter;

 public:
  typedef __LastRecursive F;
  typedef SerializedData* N;

  SerializedData* finish() {
      return result;
  }

  ValueSetter(RecordConstructor* constructor) {
    result = constructor->finishNested();
  }

 protected:
  SerializedData* result;
};

///////////////////////////////////////////////////////////////////////////////
/// \brief The PODcontainer struct
///
struct PODcontainer : Record<0 + 1, PODcontainer> {

    // fields
  struct I8 : Field<Plain<i8>, First> {};
  struct U64 : Field<Plain<u64>, I8> {};
  struct any : Field<Any, U64> {};

  enum {
    headerSize = 0 + I8::headerSize + U64::headerSize + any::headerSize,
    staticSize = 0 + I8::staticSize + U64::staticSize + any::staticSize
  };

  typedef
      ValueSetter<PODcontainer::I8,
      ValueSetter<PODcontainer::U64,
      ValueSetter<PODcontainer::any,
      ValueSetter<__LastRecursive, __LastRecursive>
      >
      >
      >
      recursive;

  static recursive create(){
      SerializedData* sd = new SerializedData(sizeof(SerializedData::rid) +
                                              PODcontainer::headerSize *
                                                  sizeof(SerializedData::hel) +
                                              PODcontainer::staticSize);
      RecordConstructor *rc = new RecordConstructor(sd);
      rc->beginNested(PODcontainer::ID, PODcontainer::staticSize, PODcontainer::headerSize);
      return PODcontainer::recursive(rc);
    }
};

struct OneInt : Record<0 + 2, OneInt> {
    // fields
  struct I : Field<Plain<i32>, First> {};

  enum {
    headerSize = 0 + I::headerSize,
    staticSize = 0 + I::staticSize
  };

  typedef
      ValueSetter<OneInt::I,
      ValueSetter<__LastRecursive, __LastRecursive>
      >
      recursive;

  static recursive create(){
      SerializedData* sd = new SerializedData(sizeof(SerializedData::rid) +
                                              headerSize *
                                                  sizeof(SerializedData::hel) +
                                              staticSize);
      RecordConstructor *rc = new RecordConstructor(sd);
      rc->beginNested(ID, staticSize, headerSize);
      return recursive(rc);
    }
};

struct Arr : Record<0 + 3, Arr> {
    // fields
  struct I : Field<Plain<i32>, First> {};
  struct A : Field<Vector<i32>, I> {};

  enum {
    headerSize = 0 + I::headerSize + A::headerSize,
    staticSize = 0 + I::staticSize + A::staticSize
  };

  typedef
      ValueSetter<Arr::I,
      ValueSetter<Arr::A,
      ValueSetter<__LastRecursive, __LastRecursive>
      >
      >
      recursive;

  static recursive create(){
      SerializedData* sd = new SerializedData(sizeof(SerializedData::rid) +
                                              headerSize *
                                                  sizeof(SerializedData::hel) +
                                              staticSize);
      RecordConstructor *rc = new RecordConstructor(sd);
      rc->beginNested(ID, staticSize, headerSize);
      return recursive(rc);
    }
};

struct Combo : Record<0 + 4, Combo> {
    // fields
  struct a : Field<Any, First> {};
  struct b : Field<Plain<int>, a> {};
  struct c : Field<Vector<double>, b> {};
  struct d : Field<VectorOfAny, c> {};

  enum {
    headerSize = 0 + a::headerSize + b::headerSize + c::headerSize + d::headerSize,
    staticSize = 0 + a::staticSize + b::staticSize + c::staticSize + d::staticSize
  };

  typedef
      ValueSetter<a,
      ValueSetter<b,
      ValueSetter<c,
      ValueSetter<d,
      ValueSetter<__LastRecursive, __LastRecursive>
      >
      >
      >
      >
      recursive;

  static recursive create(){
      SerializedData* sd = new SerializedData(sizeof(SerializedData::rid) +
                                              headerSize *
                                                  sizeof(SerializedData::hel) +
                                              staticSize);
      RecordConstructor *rc = new RecordConstructor(sd);
      rc->beginNested(ID, staticSize, headerSize);
      return recursive(rc);
    }
};

const size_t SerializedData::headerSizes[] = {
    0,
    PODcontainer::headerSize,
    OneInt::headerSize,
    Arr::headerSize,
    Combo::headerSize
};
const size_t SerializedData::staticSizes[] = {
    0,
    PODcontainer::staticSize,
    OneInt::staticSize,
    Arr::staticSize,
    Combo::staticSize
};

const size_t SerializedData::__LastType = Combo::ID;


///////////////////////////////////////////////////////////////////////////////
/// \brief main
/// \return
///
int main()
{
    Combo::recursive a = Combo::create();

    a.beginRecursive<OneInt>().set(42).finish();

    Combo::recursive::N::N::N b = a.next()
            .set(1337)
            .add(3.14)
            .add(2.99)
            .add(-121E3)
            .finish();


    b.add<Arr>().set(42)
                .add(11)
                .add(33)
                .finish();

    b.add<OneInt>().set(12).finish();

    SerializedData* sd = b.finish().finish();

    std::cout << sd->field<Combo::a>().field<OneInt::I>().value() << "\n";
    std::cout << sd->field<Combo::b>().value() << "\n";
    std::cout << sd->field<Combo::c>().size() << " ";
    std::cout << sd->field<Combo::c>().get(0) << " ";
    std::cout << sd->field<Combo::c>().get(1) << " ";
    std::cout << sd->field<Combo::c>().get(2) << "\n";
    std::cout << sd->field<Combo::d>().get(0).field<Arr::I>().value() << "\n";
    std::cout << sd->field<Combo::d>().get(0).field<Arr::A>().size() << " ";
    std::cout << sd->field<Combo::d>().get(0).field<Arr::A>().get(0) << " ";
    std::cout << sd->field<Combo::d>().get(0).field<Arr::A>().get(1) << "\n";
    std::cout << sd->field<Combo::d>().get(1).id() << "\n";


    delete sd;

    return 0;
}
