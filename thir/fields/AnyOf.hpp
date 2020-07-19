#define THIR_EXTENSION_CLASS AnyOf
#define THIR_EXTENSION_TYPE Include
#include "../extensions.hpp"

THIR_NAMESPACE_OPEN

template <SerializedData::rid ValidId, typename NextCheck>
struct IDValidator
{
    static bool check(SerializedData::rid id)
    {
        return (id==ValidId) || NextCheck::check(id);
    }
};

template <SerializedData::rid ValidId>
struct IDValidator<ValidId, __Last>
{
    static bool check(SerializedData::rid id)
    {
        return id==ValidId;
    }
};

template <typename Validator>
class AnyOf: public Any {
public:
    AnyOf(const char* staticData, const char* dynamicData, SerializedData::hel dynamicSize):
        Any(staticData, dynamicData, dynamicSize){}

#define THIR_EXTENSION_CLASS AnyOf
#define THIR_EXTENSION_TYPE Field
#include "../extensions.hpp"

    template <typename Field, typename Next>
    class Setter: public Any::Setter<Field, Next>
    {
    public:

        ValueSetter<typename Next::F, typename Next::N> set(SD serialized)
        {
            if(!Validator::check(serialized->id())) throw WrongType();

            char *data = this->constructor->dynamicData(serialized->size(), this->fuse);
            memcpy(data, serialized->data(), serialized->size());

            return ValueSetter<typename Next::F, typename Next::N>(this->constructor);
        }

        template <typename Record>
        typename Record::recursive beginRecursive()
        {
            if(!Validator::check(Record::ID)) throw WrongType();

            return Any::Setter<Field, Next>::template beginRecursive<Record>();
        }

#define THIR_EXTENSION_CLASS AnyOf
#define THIR_EXTENSION_TYPE Setter
#include "../extensions.hpp"

        Setter(RC constructor) : Any::Setter<Field, Next>(constructor) {}
    };

};

THIR_NAMESPACE_CLOSE
