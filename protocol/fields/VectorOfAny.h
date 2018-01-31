class VectorOfAny: public FieldType {
public:
    enum {
        staticSize = 0,
        headerSize = 1
    };

    VectorOfAny(const char *staticData, const char *dynamicData, SerializedData::hel dynamicSize):
        FieldType(staticData, dynamicData, dynamicSize){}

    const SerializedData get(size_t index) const {
        if(dynamicSize==0) throw WrongIndex();

        const char* offset = dynamicData;

        for(size_t i = index; i>0; --i)
        {
            if(offset-dynamicData + sizeof(SerializedData::rid) > dynamicSize) throw WrongIndex();
            SerializedData::rid id = little_to_native(*reinterpret_cast<const SerializedData::rid*>(offset));
            offset += sizeof(SerializedData::rid);
            const SerializedData::hel *headers = reinterpret_cast<const SerializedData::hel*>(offset);
            offset += SerializedData::headerSize(id)*sizeof(SerializedData::hel) + SerializedData::staticSize(id);
            if(offset-dynamicData >= dynamicSize) throw WrongIndex(); // @todo: actually it is broken structure, maybe throw that instead?
            for( size_t i = SerializedData::headerSize(id); i>0; --i, headers++)
            {
                offset += little_to_native(*headers);
            }
        }
        if(offset-dynamicData + sizeof(SerializedData::rid) > dynamicSize) throw WrongIndex();
        // extract size of the record

        SerializedData::rid id = little_to_native(*reinterpret_cast<const SerializedData::rid*>(offset));
        size_t size = sizeof(SerializedData::rid);
        const SerializedData::hel *headers = reinterpret_cast<const SerializedData::hel*>(offset+size);
        size += SerializedData::headerSize(id)*sizeof(SerializedData::hel) + SerializedData::staticSize(id);
        if(offset-dynamicData + size > dynamicSize) throw WrongIndex(); // @todo: actually it is broken structure, maybe throw that instead?
        for( size_t i = SerializedData::headerSize(id); i>0; --i, headers++)
        {
            size += little_to_native(*headers);
        }
        if(offset-dynamicData + size > dynamicSize) throw WrongIndex(); // @todo: actually it is broken structure, maybe throw that instead?
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
            return typename Record::recursive(
                        constructor->beginNested(
                            Record::ID,
                            Record::staticSize,
                            Record::headerSize
                            ));
        }

        Setter(RecordConstructor* constructor) : constructor(constructor), fuse(constructor->fuse()) {}

    protected:
        RecordConstructor* constructor;
        RecordConstructor::Fuse fuse;
    };
};

