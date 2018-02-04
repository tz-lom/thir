THIR_NAMESPACE_OPEN

template<typename Validator>
class VectorOfAnyOf: public VectorOfAny {
public:

    VectorOfAnyOf(const char *staticData, const char *dynamicData, SerializedData::hel dynamicSize):
        VectorOfAny(staticData, dynamicData, dynamicSize){}

    template <typename Field, typename Next>
    class Setter: public VectorOfAny::Setter<Field, Next>
    {
    public:

        template <typename Record>
        typename Record::recursive add()
        {
            if(!Validator::check(Record::ID)) throw WrongType();

            return VectorOfAny::Setter<Field, Next>::template add<Record>();
        }

        Setter(RC constructor) : VectorOfAny::Setter<Field, Next>(constructor) {}
    };
};

THIR_NAMESPACE_CLOSE
