#define THIR_EXTENSION_CLASS Any
#define THIR_EXTENSION_TYPE Include
#include "../extensions.hpp"

THIR_NAMESPACE_OPEN

class Any: public FieldType {
public:
    enum {
        staticSize = 0,
        headerSize = 1
    };

    Any(const char *staticData, const char *dynamicData, SerializedData::hel dynamicSize):
        FieldType(staticData, dynamicData, dynamicSize){}

    operator const SerializedData() const {
        return value();
    }

    const SerializedData value() const
    {
        return SerializedData(dynamicData, dynamicSize);
    }

    SD toSD() const
    {
        SerializedData *data = new SerializedData(dynamicData, dynamicSize);
        return SD(data);
    }

    template< typename Field > typename Field::T field() const
    {
        return SerializedData(dynamicData, dynamicSize).field<Field>();
    }

#define THIR_EXTENSION_CLASS Any
#define THIR_EXTENSION_TYPE Field
#include "../extensions.hpp"

    template <typename Field, typename Next>
    class Setter
    {
    public:
        template <typename Record>
        typename Record::recursive beginRecursive()
        {
            constructor->beginNested(
                Record::ID,
                Record::staticSize,
                Record::headerSize,
                fuse
                );
            return typename Record::recursive(constructor);
        }

        ValueSetter<typename Next::F, typename Next::N> next()
        {
            constructor->nextDynamic(fuse);
            return ValueSetter<typename Next::F, typename Next::N>(constructor);
        }
        
        ValueSetter<typename Next::F, typename Next::N> set(SD serialized)
        {
            assert(serialized);
            char *data = constructor->dynamicData(serialized->size(), fuse);
            memcpy(data, serialized->data(), serialized->size());
            constructor->nextDynamic(fuse);

            return ValueSetter<typename Next::F, typename Next::N>(constructor);            
        }

#define THIR_EXTENSION_CLASS Any
#define THIR_EXTENSION_TYPE Setter
#include "../extensions.hpp"

        Setter(RC constructor) :
            constructor(constructor),
            fuse(constructor->fuse()) {}

    protected:
        RC constructor;
        RecordConstructor::Fuse fuse;

    };
};

THIR_NAMESPACE_CLOSE
