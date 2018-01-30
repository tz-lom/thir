class Any: public FieldType {
public:
    Any(const char *staticData, const char *dynamicData, SerializedData::hel dynamicSize):
        FieldType(staticData, dynamicData, dynamicSize){}


    const SerializedData* value() const
    {
        return new SerializedData(dynamicData, dynamicSize);
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
        if(lock) throw SecondInitialization();
        lock = true;
        return typename Record::recursive(
                    constructor->beginNested(
                        Record::ID,
                        Record::staticSize,
                        Record::headerSize
                        ));
    }

    ValueSetter<typename Next::F, typename Next::N> next()
    {
        if(lockNext) throw SecondInitialization();
        lockNext = true;
        constructor->nextDynamic();
        return ValueSetter<typename Next::F, typename Next::N>(constructor);
    }

    ValueSetter(RecordConstructor* constructor) : constructor(constructor), lock(false), lockNext(false) {}

protected:
    RecordConstructor* constructor;
    bool lock;
    bool lockNext;
};
