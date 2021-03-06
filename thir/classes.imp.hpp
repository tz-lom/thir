THIR_NAMESPACE_OPEN

SerializedData::SerializedData(size_t allocate)
    : block(THIR_NULLPTR), allocated(allocate), vec(allocate) {}

SerializedData::SerializedData(const char* block, size_t allocate, bool copy)
    : block(const_cast<char*>(block)), allocated(allocate)
{
    if(copy)
    {
        this->block = THIR_NULLPTR;
        vec = std::vector<char>(block, block+allocate);
    }
}

SerializedData::SerializedData(reader readdata, void* opt)
    : block(THIR_NULLPTR), allocated(sizeof(rid)), vec(allocated)
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
    order.reserve(8);
    staticOffset.reserve(8);
    dynamicSizeOffset.reserve(8);
#ifdef THIR_PRIV_ENDCONV_ENABLE
    requiredFinish.reserve(8);
#endif
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

void RecordConstructor::nextDynamic()
{
    order.back()++;
    *reinterpret_cast<SerializedData::hel*>(data->data() +
                                          dynamicSizeOffset.back()) =
      from_native(*reinterpret_cast<SerializedData::hel*>(
          data->data() + dynamicSizeOffset.back()));
    dynamicSizeOffset.back() += sizeof(SerializedData::hel);
#ifdef THIR_PRIV_ENDCONV_ENABLE
    requiredFinish.back() = false;
#endif
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
    memset(dyn, 0, headerSize);

    size_t hOffset = sizeof(id) + static_cast<size_t>(obj - data->data());
    size_t sOffset = hOffset + headerSize * sizeof(SerializedData::hel);

    order.push_back(1);
    staticOffset.push_back(sOffset);
    dynamicSizeOffset.push_back(hOffset);
#ifdef THIR_PRIV_ENDCONV_ENABLE
    requiredFinish.push_back(headerSize>0);
#endif
}

SD RecordConstructor::finishNested(const Fuse &fuse)
{
    if(fuse.order != order.back() || fuse.level != staticOffset.size()) throw WrongCreationOrder();

#ifdef THIR_PRIV_ENDCONV_ENABLE
    if(requiredFinish.back())
    {
        nextDynamic();
    }
#endif

    order.pop_back();
    staticOffset.pop_back();
    dynamicSizeOffset.pop_back();
#ifdef THIR_PRIV_ENDCONV_ENABLE
    requiredFinish.pop_back();
#endif

    return data;
}

THIR_NAMESPACE_CLOSE
