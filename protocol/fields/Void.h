class Void: public FieldType {
public:
    Void(const char *staticData, const char *dynamicData, SerializedData::hel dynamicSize):
        FieldType(staticData, dynamicData, dynamicSize){}

    enum {
        staticSize = 0,
        headerSize = 0
    };
};

template <typename Field, typename Next>
class ValueSetter<
        Field, Next,
        typename enable_if<is_same<typename Field::T, Void >::value>::type
        //for_type<Field, Any >
        >
{
public:
    typedef Field F;
    typedef Next N;

    ValueSetter<typename Next::F, typename Next::N> next()
    {
        return ValueSetter<typename Next::F, typename Next::N>(constructor);
    }

    ValueSetter(RecordConstructor* constructor) : constructor(constructor) {}

protected:
    RecordConstructor* constructor;

};
