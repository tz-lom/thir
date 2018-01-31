#ifndef PROTO_DYNAMIC_SIZE_TYPE
# define PROTO_DYNAMIC_SIZE_TYPE uint32_t
#endif
#ifndef PROTO_ID_TYPE
# define PROTO_ID_TYPE uint16_t
#endif
#ifndef PROTO_NAMESPACE
#  define PROTO_NAMESPACE
#endif

#include <vector>
#include <stdint.h>
#include <boost/endian/conversion.hpp>
using namespace ::boost::endian;

#if __cplusplus < 201103L
#define nullptr (0)

template<bool B, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T> { typedef T type; };

template<class T, class U>
struct is_same { enum {value=false}; };

template<class T>
struct is_same<T, T> { enum {value=true}; };
#else
#include <type_traits>
using std::enable_if;
using std::is_same;
#endif

struct First {
    enum {
        staticOffset = 0,
        dynamicOffset = 0,
        headerSize = 0,
        staticSize = 0
    };
};

struct __Last {};


class SerializedData;

struct SerializedException {};
struct WrongType : SerializedException {};
struct WrongIndex : SerializedException {};
struct SecondInitialization : SerializedException {};
struct WrongCreationOrder: SerializedException {};


/////////////////////////////////////////////////////////////////////
/// \brief The SerializedData class
///
class SerializedData
{
    friend class RecordConstructor;
public:
    typedef PROTO_ID_TYPE rid;
    typedef PROTO_DYNAMIC_SIZE_TYPE hel;

    typedef void (*reader)(char* memory, size_t size, void* opt);

    SerializedData(size_t allocate);
    SerializedData(reader readdata, void* opt = nullptr);
    SerializedData(const char* block, size_t size);

    inline const char* data() const {
      if (block == nullptr) {
        return &vec[0];
      } else {
        return block;
      }
    }

    inline char* data() {
      if (block == nullptr) {
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



    static size_t headerSize(rid id);
    static size_t staticSize(rid id);

protected:
    char* block;
    size_t allocated;
    std::vector<char> vec;

    static const size_t headerSizes[];
    static const size_t staticSizes[];
    static const size_t __LastType;

    void requireSize(size_t size);
};

class RecordConstructor {
public:
    RecordConstructor(SerializedData* data);

    class Fuse {
    public:
        size_t level;
        size_t order;
    };

    char* staticData(size_t size, const Fuse &fuse);
    char* dynamicData(size_t size, const Fuse &fuse);

    void nextDynamic(const Fuse &fuse);

    Fuse fuse();

    RecordConstructor* beginNested(SerializedData::rid id,
                                   size_t staticSize,
                                   size_t headerSize,
                                   const Fuse &fuse);
    SerializedData* finishNested(const Fuse &fuse);


protected:
    size_t order;
    SerializedData* data;
    size_t dynamicOffset;
    std::vector<size_t> staticOffset;
    std::vector<size_t> dynamicSizeOffset;

    char* dynamicData(size_t size);
    void nextDynamic();
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

