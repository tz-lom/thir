#include <vector>
#include <stdint.h>
#include <cstddef>
#include <boost/endian/conversion.hpp>


#if __cplusplus < 201103L
#  include <boost/shared_ptr.hpp>
#else
#  include <memory>
#endif

THIR_NAMESPACE_OPEN

using namespace ::boost::endian;

#if __cplusplus < 201103L
#  ifndef nullptr
#    define nullptr (0)
#  endif
#endif


template <class EndianReversible >
inline EndianReversible  to_native(EndianReversible  x)
{
    return BOOST_PP_CAT(THIR_SEND_ENDIAN, _to_native)(x);
}

template <class EndianReversible >
inline EndianReversible  from_native(EndianReversible  x)
{
    return BOOST_PP_CAT(native_to_, THIR_SEND_ENDIAN)(x);
}

template<>
inline double to_native(double x)
{
    return x;
}

template<>
inline float to_native(float x)
{
    return x;
}


template<>
inline double from_native(double x)
{
    return x;
}

template<>
inline float from_native(float x)
{
    return x;
}


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
    typedef THIR_ID_TYPE rid;
    typedef THIR_DYNAMIC_SIZE_TYPE hel;

    typedef void (*reader)(char* memory, size_t size, void* opt);

    SerializedData(size_t allocate);
    SerializedData(reader readdata, void* opt = nullptr);
    SerializedData(const char* block, size_t size, bool copy = false);

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

    inline std::vector<char> vector() {
        if(block == nullptr) {
            return vec;
        } else {
            return std::vector<char>(block, block+allocated);
        }
    }

    inline rid id() const {
      if (allocated == 0)
        return 0;
      return to_native(*(reinterpret_cast<const rid*>(data())));
    }

    inline std::size_t size() const {
        if(block) return allocated;
        return vec.size();
    }

    template< typename Field > typename Field::T field() const
    {
        if (id() != Field::record::ID)
          throw WrongType();

        const char* offset =
            data() + sizeof(rid);
        const char* staticData = offset + sizeof(hel) * Field::record::headerSize;
        const char* dynamicData = staticData + Field::record::staticSize;
        for (int i = Field::dynamicOffset - 1; i >= 0; --i) {
          dynamicData += to_native(reinterpret_cast<const hel*>(offset)[i]);
        }

        return typename Field::T(
                    staticData + Field::staticOffset,
                    dynamicData,
                    to_native(reinterpret_cast<const hel*>(offset)[Field::dynamicOffset])
                );
    }

    inline static size_t headerSize(rid id) {
        if (id < 1 || id > __LastType) throw WrongType();
        return headerSizes[id];
    }

    inline static size_t staticSize(rid id) {
        if (id < 1 || id > __LastType) throw WrongType();
        return staticSizes[id];
    }

protected:
    char* block;
    size_t allocated;
    std::vector<char> vec;

    static const size_t headerSizes[];
    static const size_t staticSizes[];
    static const size_t __LastType;

    inline void requireSize(size_t size) {
        if (block) throw SerializedException();
        vec.resize(size);
        allocated = size;
    }
};

class RecordConstructor;
#if __cplusplus < 201103L
typedef ::boost::shared_ptr<RecordConstructor> RC;
typedef ::boost::shared_ptr<SerializedData> SD;
#else
typedef ::std::shared_ptr<RecordConstructor> RC;
typedef ::std::shared_ptr<SerializedData> SD;
#endif

class RecordConstructor {
public:
    RecordConstructor(SerializedData* data);

    class Fuse {
    public:
        Fuse(size_t level, size_t order);

        size_t level;
        size_t order;
    };

    char* staticData(size_t size, const Fuse &fuse);
    char* dynamicData(size_t size, const Fuse &fuse);

    void nextDynamic(const Fuse &fuse);

    Fuse fuse();

    void beginNested(SerializedData::rid id,
                   size_t staticSize,
                   size_t headerSize,
                   const Fuse &fuse);
    SD finishNested(const Fuse &fuse);

protected:
    SD data;
    size_t dynamicOffset;
    std::vector<size_t> staticOffset;
    std::vector<size_t> dynamicSizeOffset;
    std::vector<size_t> order;
#ifdef THIR_PRIV_ENDCONV_ENABLE
    std::vector<bool> requiredFinish;
#endif

    char* dynamicData(size_t size);
    void nextDynamic();
};

template <int recordId, typename self>
struct Record {
  enum { ID = recordId };

  template <typename type, typename parent>
  struct Field {
    typedef type T;

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

THIR_NAMESPACE_CLOSE
