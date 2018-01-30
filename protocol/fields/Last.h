
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
    result = constructor->finishNested();
  }

 protected:
  SerializedData* result;
};
