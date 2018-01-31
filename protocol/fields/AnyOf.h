

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
class AnyOf: public Any {
public:
    AnyOf(const char* staticData, const char* dynamicData, SerializedData::hel dynamicSize):
        Any(staticData, dynamicData, dynamicSize){}

    template <typename Field, typename Next>
    class Setter: public Any::Setter<Field, Next>
    {
    public:

        template <typename Rec>
        typename Rec::recursive beginRecursive()
        {
            if(!Validator::check(Rec::ID)) throw WrongType();

            return Any::Setter<Field, Next>::template beginRecursive<Rec>();
        }

        Setter(RecordConstructor* constructor) : Any::Setter<Field, Next>(constructor) {}
    };

};
