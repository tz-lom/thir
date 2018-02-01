
template <typename type>
class Vector: public FieldType {
public:
    enum {
        staticSize = 0,
        headerSize = 1
    };

    Vector(const char *staticData, const char *dynamicData, SerializedData::hel dynamicSize):
        FieldType(staticData, dynamicData, dynamicSize){}

    size_t size() const {
        return dynamicSize/sizeof(type);
    }

    operator ::std::vector<type>() const {
        ::std::vector<type> result(size());
        const type* data = reinterpret_cast<const type*>(dynamicData);
        for(int i=result.size()-1; i>=0; --i)
        {
            result[i] = to_native(data[i]);
        }
        return result;
    }

    const type get(size_t index) const {
        if(index>=size()) throw WrongIndex();
        return to_native(reinterpret_cast<const type*>(dynamicData)[index]);
    }


    template <typename Field, typename Next>
    class Setter
    {
    public:
        typedef Field F;
        typedef Next N;

        ValueSetter<typename Next::F, typename Next::N>
        finish()
        {
            constructor->nextDynamic(fuse);
            return ValueSetter<typename Next::F, typename Next::N>(constructor);
        }

    /*
        ValueSetter<Field, Next> add(const ::std::vector<typename Field::T::T> &vector)
        {
            typename Field::T::T* data = reinterpret_cast<typename Field::T::T*>(
                        constructor->dynamicData(sizeof(typename Field::T::T)*vector.size())
                        );

            for(int i=vector.size()-1; i>=0; --i)
            {
                data[i] = from_native(vector[i]);
            }
            return ValueSetter<Field, Next>(constructor);
        }
    */
        template <typename Iterable>
        ValueSetter<Field, Next> addVector(const Iterable &container)
        {
            typename Iterable::const_iterator first = container.begin();
            typename Iterable::const_iterator last = container.end();

            type* data = reinterpret_cast<type*>(
                        constructor->dynamicData(sizeof(type)*(last-first), fuse)
                        );
            while(first != last)
            {
                *data++ = from_native(*first++);
            }
            return *static_cast<ValueSetter<Field, Next>*>(this);
        }

        ValueSetter<Field, Next> add(type value)
        {
            *reinterpret_cast<type*>(constructor->dynamicData(sizeof(type), fuse)) = from_native(value);
            return *static_cast<ValueSetter<Field, Next>*>(this);
        }

        Setter(RC constructor) : constructor(constructor), fuse(constructor->fuse()) {}

    protected:
        RC constructor;
        RecordConstructor::Fuse fuse;
    };
};

