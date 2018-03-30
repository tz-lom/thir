#include <string>
#include <algorithm>

#define THIR_EXTENSION_CLASS String
#define THIR_EXTENSION_TYPE Include
#include "../extensions.h"

THIR_NAMESPACE_OPEN

class String: public FieldType {
public:
    enum {
        staticSize = 0,
        headerSize = 1
    };

    String(const char *staticData, const char *dynamicData, SerializedData::hel dynamicSize):
        FieldType(staticData, dynamicData, dynamicSize){}


    size_t length() const {
        return dynamicSize;
    }

    operator ::std::string() const
    {
        return std::string(dynamicData, dynamicSize);
    }

    ::std::string value() const
    {
        return this->operator ::std::string();
    }

#define THIR_EXTENSION_CLASS String
#define THIR_EXTENSION_TYPE Field
#include "../extensions.h"

    template <typename Field, typename Next>
    class Setter
    {
    public:
        typedef Field F;
        typedef Next N;

        Setter(RC constructor) : constructor(constructor), fuse(constructor->fuse()) {}

        template<typename string>
        ValueSetter<typename Next::F, typename Next::N>
        set(const string &str)
        {
            return add(str).finish();
        }

        ValueSetter<Field, Next>
        add(const std::string &str)
        {
            char* const data = reinterpret_cast<char* const>(constructor->dynamicData(sizeof(char)*str.length(), fuse));
            ::std::copy(str.begin(), str.end(), data);
            return *static_cast<ValueSetter<Field, Next>*>(this);
        }

        ValueSetter<typename Next::F, typename Next::N>
        finish()
        {
            constructor->nextDynamic(fuse);
            return ValueSetter<typename Next::F, typename Next::N>(constructor);
        }

#define THIR_EXTENSION_CLASS String
#define THIR_EXTENSION_TYPE Setter
#include "../extensions.h"

    protected:
        RC constructor;
        RecordConstructor::Fuse fuse;
    };
};

THIR_NAMESPACE_CLOSE
