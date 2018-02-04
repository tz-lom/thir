THIR_NAMESPACE_OPEN

class VectorOfAny: public FieldType {
public:
    enum {
        staticSize = 0,
        headerSize = 1
    };

    VectorOfAny(const char *staticData, const char *dynamicData, SerializedData::hel dynamicSize):
        FieldType(staticData, dynamicData, dynamicSize){}

    size_t size() const {
        if(dynamicSize == 0) return 0;

        const char* offset = dynamicData;
        const char* end = dynamicData+dynamicSize;

        size_t result = 0;
        while(offset<end)
        {
            if(offset + sizeof(SerializedData::rid) > end) throw WrongIndex(); // @todo: throw broken structure
            SerializedData::rid id = to_native(*reinterpret_cast<const SerializedData::rid*>(offset));
            offset += sizeof(SerializedData::rid);
            const SerializedData::hel *headers = reinterpret_cast<const SerializedData::hel*>(offset);
            offset += SerializedData::headerSize(id)*sizeof(SerializedData::hel) + SerializedData::staticSize(id);
            if(offset > end) throw WrongIndex(); // @todo: actually it is broken structure, maybe throw that instead?
            for( size_t i = SerializedData::headerSize(id); i>0; --i, headers++)
            {
                offset += to_native(*headers);
            }
            result ++;
        }
        return result;
    }

    const SerializedData get(size_t index) const {
        if(dynamicSize==0) throw WrongIndex();

        const char* offset = dynamicData;
        const char* end = dynamicData+dynamicSize;


        for(size_t i = index; i>0; --i)
        {
            if(offset + sizeof(SerializedData::rid) > end) throw WrongIndex();
            SerializedData::rid id = to_native(*reinterpret_cast<const SerializedData::rid*>(offset));
            offset += sizeof(SerializedData::rid);
            const SerializedData::hel *headers = reinterpret_cast<const SerializedData::hel*>(offset);
            offset += SerializedData::headerSize(id)*sizeof(SerializedData::hel) + SerializedData::staticSize(id);
            if(offset > end) throw WrongIndex(); // @todo: actually it is broken structure, maybe throw that instead?
            for( size_t i = SerializedData::headerSize(id); i>0; --i, headers++)
            {
                offset += to_native(*headers);
            }
        }
        if(offset + sizeof(SerializedData::rid) > end) throw WrongIndex();
        // extract size of the record

        SerializedData::rid id = to_native(*reinterpret_cast<const SerializedData::rid*>(offset));
        size_t size = sizeof(SerializedData::rid);
        const SerializedData::hel *headers = reinterpret_cast<const SerializedData::hel*>(offset+size);
        size += SerializedData::headerSize(id)*sizeof(SerializedData::hel) + SerializedData::staticSize(id);
        if(offset + size > end) throw WrongIndex(); // @todo: actually it is broken structure, maybe throw that instead?
        for( size_t i = SerializedData::headerSize(id); i>0; --i, headers++)
        {
            size += to_native(*headers);
        }
        if(offset + size > end) throw WrongIndex(); // @todo: actually it is broken structure, maybe throw that instead?
        return SerializedData(offset, size);
    }

    template <typename Field, typename Next>
    class Setter
    {
    public:
        ValueSetter<typename Next::F, typename Next::N>
        finish()
        {
            constructor->nextDynamic(fuse);
            return ValueSetter<typename Next::F, typename Next::N>(constructor);
        }

        template <typename Record>
        typename Record::recursive add()
        {
            constructor->beginNested(
                Record::ID,
                Record::staticSize,
                Record::headerSize,
                fuse
                );
            return typename Record::recursive(constructor);
        }

        Setter(RC constructor) : constructor(constructor), fuse(constructor->fuse()) {}

    protected:
        RC constructor;
        RecordConstructor::Fuse fuse;
    };
};

THIR_NAMESPACE_CLOSE