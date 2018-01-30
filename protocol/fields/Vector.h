template <typename type>
class Vector: public FieldType {
public:
    typedef type T;

    Vector(const char *staticData, const char *dynamicData, SerializedData::hel dynamicSize):
        FieldType(staticData, dynamicData, dynamicSize){}

    size_t size() const {
        return dynamicSize/sizeof(type);
    }

    const type get(size_t index) const {
        if(index>=size()) throw WrongIndex();
        return little_to_native(reinterpret_cast<const type*>(dynamicData)[index]);
    }

    enum {
        staticSize = 0,
        headerSize = 1
    };
};

template <typename Field, typename Next>
class ValueSetter<
        Field, Next,
        typename enable_if<is_same<typename Field::T, Vector<typename Field::T::T> >::value>::type
        //for_type<Field, Vector<typename Field::T::T> >
        >
{
public:
    typedef Field F;
    typedef Next N;

    ValueSetter<typename Next::F, typename Next::N>
    finish()
    {
        constructor->nextDynamic();
        return ValueSetter<typename Next::F, typename Next::N>(constructor);
    }

    ValueSetter<Field, Next> add(typename Field::T::T value)
    {
        *reinterpret_cast<typename Field::T::T*>(constructor->dynamicData(sizeof(typename Field::T::T))) = native_to_little(value);
        return ValueSetter<Field, Next>(constructor);
    }

    ValueSetter(RecordConstructor* constructor) : constructor(constructor) {}

protected:
    RecordConstructor* constructor;
};
