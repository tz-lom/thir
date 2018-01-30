

struct One : Record<0 + 1, One> {
  struct a : Field<Plain<i32>, First> {};
  enum { headerSize = 0 + a::headerSize, staticSize = 0 + a::staticSize };
  typedef ValueSetter<One::a, ValueSetter<__Last, __Last> > recursive;
  static recursive create();
};
struct Two : Record<1 + 1, Two> {
  struct a : Field<Plain<i32>, First> {};
  struct b : Field<Plain<f64>, a> {};
  enum {
    headerSize = 0 + a::headerSize + b::headerSize,
    staticSize = 0 + a::staticSize + b::staticSize
  };
  typedef ValueSetter<Two::a,
                      ValueSetter<Two::b, ValueSetter<__Last, __Last> > >
      recursive;
  static recursive create();
};
struct Three : Record<2 + 1, Three> {
  struct a : Field<Plain<i32>, First> {};
  struct b : Field<Vector<i16>, a> {};
  enum {
    headerSize = 0 + a::headerSize + b::headerSize,
    staticSize = 0 + a::staticSize + b::staticSize
  };
  typedef ValueSetter<Three::a,
                      ValueSetter<Three::b, ValueSetter<__Last, __Last> > >
      recursive;
  static recursive create();
};
struct Four : Record<3 + 1, Four> {
  struct __void : Field<Void, First> {};
  enum {
    headerSize = 0 + __void::headerSize,
    staticSize = 0 + __void::staticSize
  };
  typedef ValueSetter<Four::__void, ValueSetter<__Last, __Last> > recursive;
  static recursive create();
};
struct Five : Record<4 + 1, Five> {
  struct a : Field<Any, First> {};
  struct b : Field<Any, a> {};
  enum {
    headerSize = 0 + a::headerSize + b::headerSize,
    staticSize = 0 + a::staticSize + b::staticSize
  };
  typedef ValueSetter<Five::a,
                      ValueSetter<Five::b, ValueSetter<__Last, __Last> > >
      recursive;
  static recursive create();
};
struct AVector : Record<5 + 1, AVector> {
  struct str : Field<VectorOfAny, First> {};
  enum { headerSize = 0 + str::headerSize, staticSize = 0 + str::staticSize };
  typedef ValueSetter<AVector::str, ValueSetter<__Last, __Last> > recursive;
  static recursive create();
};
struct String : Record<6 + 1, String> {
  struct str : Field<Vector<char>, First> {};
  enum { headerSize = 0 + str::headerSize, staticSize = 0 + str::staticSize };
  typedef ValueSetter<String::str, ValueSetter<__Last, __Last> > recursive;
  static recursive create();
};
struct Rec : Record<7 + 1, Rec> {
  struct ids : Field<Vector<i64>, First> {};
  struct strings : Field<VectorOfAny, ids> {};
  enum {
    headerSize = 0 + ids::headerSize + strings::headerSize,
    staticSize = 0 + ids::staticSize + strings::staticSize
  };
  typedef ValueSetter<Rec::ids,
                      ValueSetter<Rec::strings, ValueSetter<__Last, __Last> > >
      recursive;
  static recursive create();
};
struct Str : Record<8 + 1, Str> {
  struct str : Field<Vector<char>, First> {};
  enum { headerSize = 0 + str::headerSize, staticSize = 0 + str::staticSize };
  typedef ValueSetter<Str::str, ValueSetter<__Last, __Last> > recursive;
  static recursive create();
};

One::recursive One::create() {
  SerializedData* sd =
      new SerializedData(sizeof(SerializedData::rid) +
                         headerSize * sizeof(SerializedData::hel) + staticSize);
  RecordConstructor* rc = new RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize);
  return recursive(rc);
}
Two::recursive Two::create() {
  SerializedData* sd =
      new SerializedData(sizeof(SerializedData::rid) +
                         headerSize * sizeof(SerializedData::hel) + staticSize);
  RecordConstructor* rc = new RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize);
  return recursive(rc);
}
Three::recursive Three::create() {
  SerializedData* sd =
      new SerializedData(sizeof(SerializedData::rid) +
                         headerSize * sizeof(SerializedData::hel) + staticSize);
  RecordConstructor* rc = new RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize);
  return recursive(rc);
}
Four::recursive Four::create() {
  SerializedData* sd =
      new SerializedData(sizeof(SerializedData::rid) +
                         headerSize * sizeof(SerializedData::hel) + staticSize);
  RecordConstructor* rc = new RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize);
  return recursive(rc);
}
Five::recursive Five::create() {
  SerializedData* sd =
      new SerializedData(sizeof(SerializedData::rid) +
                         headerSize * sizeof(SerializedData::hel) + staticSize);
  RecordConstructor* rc = new RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize);
  return recursive(rc);
}
AVector::recursive AVector::create() {
  SerializedData* sd =
      new SerializedData(sizeof(SerializedData::rid) +
                         headerSize * sizeof(SerializedData::hel) + staticSize);
  RecordConstructor* rc = new RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize);
  return recursive(rc);
}
String::recursive String::create() {
  SerializedData* sd =
      new SerializedData(sizeof(SerializedData::rid) +
                         headerSize * sizeof(SerializedData::hel) + staticSize);
  RecordConstructor* rc = new RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize);
  return recursive(rc);
}
Rec::recursive Rec::create() {
  SerializedData* sd =
      new SerializedData(sizeof(SerializedData::rid) +
                         headerSize * sizeof(SerializedData::hel) + staticSize);
  RecordConstructor* rc = new RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize);
  return recursive(rc);
}
Str::recursive Str::create() {
  SerializedData* sd =
      new SerializedData(sizeof(SerializedData::rid) +
                         headerSize * sizeof(SerializedData::hel) + staticSize);
  RecordConstructor* rc = new RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize);
  return recursive(rc);
}
const size_t SerializedData::headerSizes[] = {0,
                                              One::headerSize,
                                              Two::headerSize,
                                              Three::headerSize,
                                              Four::headerSize,
                                              Five::headerSize,
                                              AVector::headerSize,
                                              String::headerSize,
                                              Rec::headerSize,
                                              Str::headerSize};
const size_t SerializedData::staticSizes[] = {0,
                                              One::staticSize,
                                              Two::staticSize,
                                              Three::staticSize,
                                              Four::staticSize,
                                              Five::staticSize,
                                              AVector::staticSize,
                                              String::staticSize,
                                              Rec::staticSize,
                                              Str::staticSize};
const size_t SerializedData::__LastType = Str::ID;
