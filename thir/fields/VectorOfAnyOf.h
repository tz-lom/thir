#define THIR_EXTENSION_CLASS VectorOfAnyOf
#define THIR_EXTENSION_TYPE Include
#include "../extensions.h"

THIR_NAMESPACE_OPEN

template<typename Validator>
class VectorOfAnyOf: public VectorOfAny {
public:

    VectorOfAnyOf(const char *staticData, const char *dynamicData, SerializedData::hel dynamicSize):
        VectorOfAny(staticData, dynamicData, dynamicSize){}

#define THIR_EXTENSION_CLASS VectorOfAnyOf
#define THIR_EXTENSION_TYPE Field
#include "../extensions.h"

    template <typename Field, typename Next>
    class Setter: public VectorOfAny::Setter<Field, Next>
    {
    public:

        template <typename Record>
        typename Record::recursive add()
        {
            if(!Validator::check(Record::ID)) throw WrongType();

            return VectorOfAny::Setter<Field, Next>::template add<Record>();
        }

#define THIR_EXTENSION_CLASS VectorOfAnyOf
#define THIR_EXTENSION_TYPE Setter
#include "../extensions.h"

        Setter(RC constructor) : VectorOfAny::Setter<Field, Next>(constructor) {}
    };
};

THIR_NAMESPACE_CLOSE
