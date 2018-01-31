#include <iostream>

#include "protocol/classes.h"
#include "protocol/classes.imp.h"
#include "protocol/fields/all.h"


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
      ValueSetter<__Last, __Last>
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
      rc->beginNested(PODcontainer::ID, PODcontainer::staticSize, PODcontainer::headerSize, 1, 1);
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
      ValueSetter<__Last, __Last>
      >
      recursive;

  static recursive create(){
      SerializedData* sd = new SerializedData(sizeof(SerializedData::rid) +
                                              headerSize *
                                                  sizeof(SerializedData::hel) +
                                              staticSize);
      RecordConstructor *rc = new RecordConstructor(sd);
      rc->beginNested(ID, staticSize, headerSize, 1, 1);
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
      ValueSetter<__Last, __Last>
      >
      >
      recursive;

  static recursive create(){
      SerializedData* sd = new SerializedData(sizeof(SerializedData::rid) +
                                              headerSize *
                                                  sizeof(SerializedData::hel) +
                                              staticSize);
      RecordConstructor *rc = new RecordConstructor(sd);
      rc->beginNested(ID, staticSize, headerSize, 1, 1);
      return recursive(rc);
    }
};

struct Combo : Record<0 + 4, Combo> {
    // fields
  struct a : Field<AnyOf<IDValidator<OneInt::ID, __Last> > , First> {};
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
      ValueSetter<__Last, __Last>
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
      rc->beginNested(ID, staticSize, headerSize, 1, 1);
      return recursive(rc, 1, 1);
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

    IDValidator<10, IDValidator<3, IDValidator<5, __Last> > > v;

    std::cout << v.check(4) << v.check(10) << v.check(5) << v.check(6)  << "\n";


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
