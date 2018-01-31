class Any: public FieldType {
public:
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

    enum {
        staticSize = 0,
        headerSize = 1
    };
};

template <typename Field, typename Next>
class ValueSetter<
        Field, Next,
        typename enable_if<is_same<typename Field::T, Any >::value>::type
        //for_type<Field, Any >
        >
{
public:
    typedef Field F;
    typedef Next N;

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

    ValueSetter(RecordConstructor* constructor) :
        constructor(constructor),
        fuse(constructor->fuse()) {}

protected:
    RecordConstructor* constructor;
    RecordConstructor::Fuse fuse;

};
