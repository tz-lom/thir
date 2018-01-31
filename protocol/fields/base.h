class FieldType
{
public:
    FieldType( const char* staticData, const char* dynamicData, SerializedData::hel dynamicSize):
        staticData(staticData),
        dynamicData(dynamicData),
        dynamicSize(dynamicSize)
    {
    }

protected:
    const char *staticData;
    const char *dynamicData;
    const SerializedData::hel dynamicSize;
};


template <typename Field, typename Next, typename Dummy = void>
class ValueSetter;

template <typename Next>
class ValueSetter<__Last, Next> {
  template <typename _Field, typename _Next, typename _Dummy>
  friend class ValueSetter;

 public:
  typedef __Last F;
  typedef SerializedData* N;

  SerializedData* finish() {
      return result;
  }

  ValueSetter(RecordConstructor* constructor) {
    result = constructor->finishNested(constructor->fuse());
  }

 protected:
  SerializedData* result;
};
