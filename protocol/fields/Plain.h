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


    template <typename Field, typename Next>
    class Setter
    {
    public:
        ValueSetter<typename Next::F, typename Next::N> set(const type value)
        {

          *(reinterpret_cast<type*>(
              constructor->staticData(Field::staticSize, fuse))) = from_native(value);

          return ValueSetter<typename Next::F, typename Next::N>(constructor);
        }

        Setter(RecordConstructor* constructor) : constructor(constructor), fuse(constructor->fuse()) {}

    protected:
        RecordConstructor* constructor;
        RecordConstructor::Fuse fuse;
    };

};

