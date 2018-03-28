#include <string>

THIR_NAMESPACE_OPEN

class String: public FieldType {
public:
    enum {
        staticSize = 0,
        headerSize = 1
    };


    size_t length() const {
        return dynamicSize;
    }

    operator ::std::string() const {
        return std::string(dynamicData, dynamicSize);
    }

    template <typename Field, typename Next>
    class Setter
    {
    public:
        typedef Field F;
        typedef Next N;

        Setter(RC constructor) : constructor(constructor), fuse(constructor->fuse()) {}

        ValueSetter<typename Next::F, typename Next::N>
        set(const std::string &str)
        {
            return add(str).finish();
        }

        ValueSetter<Field, Next>
        add(const std::string &str)
        {
            char* const data = reinterpret_cast<char* const>(constructor->dynamicData(sizeof(char)*str.length(), fuse));
            for(size_t i=0, sz=str.length(); i<sz; ++i)
            {
                data[i] = str[i];
            }
            return this;
        }

        ValueSetter<typename Next::F, typename Next::N>
        finish()
        {
            constructor->nextDynamic(fuse);
            return ValueSetter<typename Next::F, typename Next::N>(constructor);
        }

    protected:
        RC constructor;
        RecordConstructor::Fuse fuse;
    };
};

THIR_NAMESPACE_CLOSE
