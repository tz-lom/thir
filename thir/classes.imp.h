THIR_NAMESPACE_OPEN

SerializedData::SerializedData(size_t allocate)
    : block(nullptr), allocated(allocate), vec(allocate) {}

SerializedData::SerializedData(const char* block, size_t allocate)
    : block(const_cast<char*>(block)), allocated(allocate), vec() {}

void SerializedData::requireSize(size_t size)
{
    if (block) throw SerializedException();
    vec.resize(size);
    allocated = size;
}

inline size_t SerializedData::headerSize(rid id)
{
    if (id < 1 || id > __LastType) throw WrongType();
    return headerSizes[id];
}

size_t SerializedData::staticSize(SerializedData::rid id)
{
    if (id < 1 || id > __LastType) throw WrongType();
    return staticSizes[id];
}
std::size_t SerializedData::size() const
{
    if(block) return allocated;
    return vec.size();
}

SerializedData::SerializedData(reader readdata, void* opt)
    : block(nullptr), allocated(sizeof(rid)), vec(allocated)
{
    readdata(data(), sizeof(rid), opt);

    rid id = to_native(*reinterpret_cast<rid*>(data()));

    size_t hs = headerSize(id);

    allocated += hs * sizeof(hel);
    requireSize(allocated);

    hel* header = reinterpret_cast<hel*>(data() + sizeof(rid));

    readdata(reinterpret_cast<char*>(header), sizeof(hel) * hs, opt);
    std::size_t bulkSize = staticSizes[id];
    for (unsigned int i = 0; i < hs; ++i)
    {
        bulkSize += to_native(header[i]);
    }

    allocated += bulkSize;
    requireSize(allocated);

    readdata(data() + sizeof(rid) + sizeof(hel) * hs, bulkSize, opt);
}

RecordConstructor::Fuse::Fuse(size_t level, size_t order):
    level(level),
    order(order)
{
}

RecordConstructor::RecordConstructor(SerializedData* data)
    : data(data),
      dynamicOffset(0)
{
}

RecordConstructor::Fuse RecordConstructor::fuse()
{
    return Fuse(staticOffset.size(), order.back());
}


char* RecordConstructor::staticData(size_t size, const Fuse &fuse)
{
    if(fuse.order != order.back() || fuse.level != staticOffset.size()) throw WrongCreationOrder();

    order.back()++;
    char* ptr = data->data() + staticOffset.back();
    staticOffset.back() += size;
    return ptr;
}

char* RecordConstructor::dynamicData(size_t size, const Fuse &fuse)
{
    if(fuse.order != order.back() || fuse.level != staticOffset.size()) throw WrongCreationOrder();
    return dynamicData(size);
}

char* RecordConstructor::dynamicData(size_t size)
{
    data->requireSize(dynamicOffset + size);
    char* ptr = data->data() + dynamicOffset;
    dynamicOffset += size;

    for (std::vector<size_t>::iterator i = dynamicSizeOffset.begin(), e = dynamicSizeOffset.end();
       i != e; ++i)
    {
        *reinterpret_cast<SerializedData::hel*>(data->data() + *i) += size;
    }

    return ptr;
}

void RecordConstructor::nextDynamic(const Fuse &fuse)
{
    if(fuse.order != order.back() || fuse.level != staticOffset.size()) throw WrongCreationOrder();

    nextDynamic();
}

void RecordConstructor::cancelCreation()
{
    delete data;
}

void RecordConstructor::nextDynamic()
{
    order.back()++;
    *reinterpret_cast<SerializedData::hel*>(data->data() +
                                          dynamicSizeOffset.back()) =
      from_native(*reinterpret_cast<SerializedData::hel*>(
          data->data() + dynamicSizeOffset.back()));
    dynamicSizeOffset.back() += sizeof(SerializedData::hel);
    requiredFinish.back() = false;
}


void RecordConstructor::beginNested(SerializedData::rid id,
                                  size_t staticSize,
                                  size_t headerSize,
                                  const Fuse &fuse)
{
    if(fuse.order != 0 && (fuse.order != order.back() || fuse.level != staticOffset.size())) throw WrongCreationOrder();


    size_t nestedSize = sizeof(id) + staticSize + headerSize * sizeof(SerializedData::hel);
    char* obj = dynamicData(nestedSize);
    *reinterpret_cast<SerializedData::rid*>(obj) = from_native(id);

    SerializedData::hel* dyn =
      reinterpret_cast<SerializedData::hel*>(obj + sizeof(SerializedData::rid));
    for (size_t j = headerSize; j > 0; --j, ++dyn)
        *dyn = 0;

    size_t hOffset = sizeof(id) + static_cast<size_t>(obj - data->data());
    size_t sOffset = hOffset + headerSize * sizeof(SerializedData::hel);

    order.push_back(1);
    staticOffset.push_back(sOffset);
    dynamicSizeOffset.push_back(hOffset);
    requiredFinish.push_back(headerSize>0);
}

SerializedData* RecordConstructor::finishNested(const Fuse &fuse)
{
    if(fuse.order != order.back() || fuse.level != staticOffset.size()) throw WrongCreationOrder();

    if(requiredFinish.back())
    {
        nextDynamic();
    }

    order.pop_back();
    staticOffset.pop_back();
    dynamicSizeOffset.pop_back();
    requiredFinish.pop_back();

    SerializedData *data = this->data;

    return data;
}

THIR_NAMESPACE_CLOSE
