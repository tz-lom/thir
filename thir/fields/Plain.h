THIR_NAMESPACE_OPEN

template <typename type>
class Plain: public FieldType {
public:
    enum {
        staticSize = sizeof(type),
        headerSize = 0
    };

    Plain(const char *staticData, const char *dynamicData, SerializedData::hel dynamicSize):
        FieldType(staticData, dynamicData, dynamicSize){}

    operator const type() const {
        return value();
    }

    const type value() const {
        return to_native(*(reinterpret_cast<const type*>(staticData)));
    }

    void set(const type value) {
        *(reinterpret_cast<type*>(const_cast<char*>(staticData))) = from_native(value);
    }


    template <typename Field, typename Next>
    class Setter
    {
    public:

        void update(const type value)
        {
            *field = from_native(value);
        }

        ValueSetter<typename Next::F, typename Next::N> set(const type value)
        {
            if(block) throw WrongCreationOrder();
            *field = from_native(value);
            block = true;

            return ValueSetter<typename Next::F, typename Next::N>(constructor);
        }

        Setter(RC constructor) :
            constructor(constructor),
            fuse(constructor->fuse()),
            block(false),
            field(reinterpret_cast<type*>(constructor->staticData(Field::staticSize, fuse)))
        {}

    protected:
        RC constructor;
        RecordConstructor::Fuse fuse;
        bool block;
        type *field;
    };

};

THIR_NAMESPACE_CLOSE
