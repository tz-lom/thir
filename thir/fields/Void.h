THIR_NAMESPACE_OPEN

class Void: public FieldType {
public:

    enum {
        staticSize = 0,
        headerSize = 0
    };

    Void(const char *staticData, const char *dynamicData, SerializedData::hel dynamicSize):
        FieldType(staticData, dynamicData, dynamicSize){}


    template <typename Field, typename Next>
    class Setter
    {
    public:
        ValueSetter<typename Next::F, typename Next::N> next()
        {
            return ValueSetter<typename Next::F, typename Next::N>(constructor);
        }

        Setter(RC constructor) : constructor(constructor) {}

    protected:
        RC constructor;

    };
};

THIR_NAMESPACE_CLOSE
