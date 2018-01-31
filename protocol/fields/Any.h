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
            return typename Record::recursive(
                        constructor->beginNested(
                            Record::ID,
                            Record::staticSize,
                            Record::headerSize,
                            fuse
                            ));
        }

        ValueSetter<typename Next::F, typename Next::N> next()
        {
            constructor->nextDynamic(fuse);
            return ValueSetter<typename Next::F, typename Next::N>(constructor);
        }

        Setter(RecordConstructor* constructor) :
            constructor(constructor),
            fuse(constructor->fuse()) {}

    protected:
        RecordConstructor* constructor;
        RecordConstructor::Fuse fuse;

    };
};

