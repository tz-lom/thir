class Any: public FieldType {
public:
    enum {
        staticSize = 0,
        headerSize = 1
    };

    Any(const char *staticData, const char *dynamicData, SerializedData::hel dynamicSize):
        FieldType(staticData, dynamicData, dynamicSize){}


    const SerializedData value() const
    {
        return SerializedData(dynamicData, dynamicSize);
    }

    template< typename Field > typename Field::T field() const
    {
        return SerializedData(dynamicData, dynamicSize).field<Field>();
    }

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

        Setter(RC constructor) :
            constructor(constructor),
            fuse(constructor->fuse()) {}

    protected:
        RC constructor;
        RecordConstructor::Fuse fuse;

    };
};

