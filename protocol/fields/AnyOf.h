
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
class AnyOf: public FieldType {
public:
    typedef Validator V;

    AnyOf(const char* staticData, const char* dynamicData, SerializedData::hel dynamicSize):
        FieldType(staticData, dynamicData, dynamicSize){}

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
        typename enable_if<is_same<typename Field::T, AnyOf<typename Field::T::V> >::value>::type
        >
{
public:
    typedef Field F;
    typedef Next N;

    template <typename Record>
    typename Record::recursive beginRecursive()
    {
        if(!Field::T::V::check(Record::ID)) throw WrongType();
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
