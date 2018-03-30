#define THIR_EXTENSION_CLASS Vector
#define THIR_EXTENSION_TYPE Include
#include "../extensions.h"


THIR_NAMESPACE_OPEN

template <typename type>
class Vector: public FieldType {
public:
    enum {
        staticSize = 0,
        headerSize = 1
    };

    Vector(const char *staticData, const char *dynamicData, SerializedData::hel dynamicSize):
        FieldType(staticData, dynamicData, dynamicSize){}

    size_t size() const {
        return dynamicSize/sizeof(type);
    }

    operator ::std::vector<type>() const {
        return toVector();
    }

    ::std::vector<type> toVector() const {
        ::std::vector<type> result(size());
        const type* data = reinterpret_cast<const type*>(dynamicData);
        for(int i=result.size()-1; i>=0; --i)
        {
            result[i] = to_native(data[i]);
        }
        return result;
    }

    const type get(size_t index) const {
        if(index>=size()) throw WrongIndex();
        return to_native(reinterpret_cast<const type*>(dynamicData)[index]);
    }

#define THIR_EXTENSION_CLASS Vector
#define THIR_EXTENSION_TYPE Field
#include "../extensions.h"

    template <typename Field, typename Next>
    class Setter
    {
    public:
        typedef Field F;
        typedef Next N;

        ValueSetter<typename Next::F, typename Next::N>
        finish()
        {
            constructor->nextDynamic(fuse);
            return ValueSetter<typename Next::F, typename Next::N>(constructor);
        }

        template <typename Iterable>
        ValueSetter<typename Next::F, typename Next::N>
        set(const Iterable &container)
        {
            return addVector(container).finish();
        }

        template <typename Iterator>
        ValueSetter<typename Next::F, typename Next::N>
        set(Iterator first, Iterator last)
        {
            return add(first, last).finish();
        }

        template <typename Iterable>
        ValueSetter<Field, Next> addVector(const Iterable &container)
        {
            return add(container.begin(), container.end());
        }

        template <typename Iterator>
        ValueSetter<Field, Next> add(Iterator first, Iterator last)
        {
            type* data = reinterpret_cast<type*>(
                        constructor->dynamicData(sizeof(type)*(last-first), fuse)
                        );
            while(first != last)
            {
                *data++ = from_native(*first++);
            }
            return *static_cast<ValueSetter<Field, Next>*>(this);
        }

        ValueSetter<Field, Next> add(type value)
        {
            *reinterpret_cast<type*>(constructor->dynamicData(sizeof(type), fuse)) = from_native(value);
            return *static_cast<ValueSetter<Field, Next>*>(this);
        }

#define THIR_EXTENSION_CLASS Vector
#define THIR_EXTENSION_TYPE Setter
#include "../extensions.h"

        Setter(RC constructor) : constructor(constructor), fuse(constructor->fuse()) {}

    protected:
        RC constructor;
        RecordConstructor::Fuse fuse;
    };
};


THIR_NAMESPACE_CLOSE
