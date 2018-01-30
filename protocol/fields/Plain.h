template <typename type>
class Plain: public FieldType {
public:
    typedef type T;

    Plain(const char *staticData, const char *dynamicData, SerializedData::hel dynamicSize):
        FieldType(staticData, dynamicData, dynamicSize){}

    operator const type() const {
        return value();
    }

    const type value() const {
        return little_to_native(*(reinterpret_cast<const type*>(staticData)));
    }

    enum {
        staticSize = sizeof(type),
        headerSize = 0
    };
};

template <typename Field, typename Next>
class ValueSetter<
        Field, Next,
        typename enable_if<is_same<typename Field::T, Plain<typename Field::T::T> >::value>::type
        //for_type<typename Field::T, Plain<typename Field::T::T> >
        >
{
public:
    typedef Field F;
    typedef Next N;

    ValueSetter<typename Next::F, typename Next::N>
    set(const typename Field::T::T value)
    {

      *(reinterpret_cast<typename Field::T::T*>(
          constructor->staticData(Field::staticSize))) = native_to_little(value);

      return ValueSetter<typename Next::F, typename Next::N>(constructor);
    }

    ValueSetter(RecordConstructor* constructor) : constructor(constructor) {}

protected:
    RecordConstructor* constructor;
};
