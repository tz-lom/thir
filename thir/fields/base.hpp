THIR_NAMESPACE_OPEN

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


template <typename Field, typename Next>
class ValueSetter: public Field::T::template Setter<Field, Next>
{
public:
    typedef Field F;
    typedef Next N;

    ValueSetter(RC constructor):
        Field::T:: template Setter<Field, Next>(constructor)
    {}
};

template<>
class ValueSetter<__Last, __Last> {
 public:
  typedef __Last F;
  typedef __Last N;

  SD finish() {
      return result;
  }

  ValueSetter(RC constructor) {
    result = constructor->finishNested(constructor->fuse());
  }

 protected:
  SD result;
};

THIR_NAMESPACE_CLOSE
