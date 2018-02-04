

struct One : THIR_NAMESPACE::Record<0 + 1, One> {
  struct a : Field<THIR_NAMESPACE::Plain<i32>, THIR_NAMESPACE::First> {};
  enum { headerSize = 0 + a::headerSize, staticSize = 0 + a::staticSize };
  typedef THIR_NAMESPACE::ValueSetter<
      One::a,
      THIR_NAMESPACE::ValueSetter<THIR_NAMESPACE::__Last,
                                   THIR_NAMESPACE::__Last> >
      recursive;
  static recursive create();
};
struct Two : THIR_NAMESPACE::Record<1 + 1, Two> {
  struct a : Field<THIR_NAMESPACE::Plain<i32>, THIR_NAMESPACE::First> {};
  struct b : Field<THIR_NAMESPACE::Plain<f64>, a> {};
  enum {
    headerSize = 0 + a::headerSize + b::headerSize,
    staticSize = 0 + a::staticSize + b::staticSize
  };
  typedef THIR_NAMESPACE::ValueSetter<
      Two::a,
      THIR_NAMESPACE::ValueSetter<
          Two::b,
          THIR_NAMESPACE::ValueSetter<THIR_NAMESPACE::__Last,
                                       THIR_NAMESPACE::__Last> > >
      recursive;
  static recursive create();
};
struct Three : THIR_NAMESPACE::Record<2 + 1, Three> {
  struct a : Field<THIR_NAMESPACE::Plain<i32>, THIR_NAMESPACE::First> {};
  struct b : Field<THIR_NAMESPACE::Vector<i16>, a> {};
  enum {
    headerSize = 0 + a::headerSize + b::headerSize,
    staticSize = 0 + a::staticSize + b::staticSize
  };
  typedef THIR_NAMESPACE::ValueSetter<
      Three::a,
      THIR_NAMESPACE::ValueSetter<
          Three::b,
          THIR_NAMESPACE::ValueSetter<THIR_NAMESPACE::__Last,
                                       THIR_NAMESPACE::__Last> > >
      recursive;
  static recursive create();
};
struct Four : THIR_NAMESPACE::Record<3 + 1, Four> {
  struct __void : Field<THIR_NAMESPACE::Void, THIR_NAMESPACE::First> {};
  enum {
    headerSize = 0 + __void::headerSize,
    staticSize = 0 + __void::staticSize
  };
  typedef THIR_NAMESPACE::ValueSetter<
      Four::__void,
      THIR_NAMESPACE::ValueSetter<THIR_NAMESPACE::__Last,
                                   THIR_NAMESPACE::__Last> >
      recursive;
  static recursive create();
};
struct Five : THIR_NAMESPACE::Record<4 + 1, Five> {
  struct a : Field<THIR_NAMESPACE::Any, THIR_NAMESPACE::First> {};
  struct b : Field<THIR_NAMESPACE::Any, a> {};
  enum {
    headerSize = 0 + a::headerSize + b::headerSize,
    staticSize = 0 + a::staticSize + b::staticSize
  };
  typedef THIR_NAMESPACE::ValueSetter<
      Five::a,
      THIR_NAMESPACE::ValueSetter<
          Five::b,
          THIR_NAMESPACE::ValueSetter<THIR_NAMESPACE::__Last,
                                       THIR_NAMESPACE::__Last> > >
      recursive;
  static recursive create();
};
struct Six : THIR_NAMESPACE::Record<5 + 1, Six> {
  struct a : Field<THIR_NAMESPACE::VectorOfAny, THIR_NAMESPACE::First> {};
  enum { headerSize = 0 + a::headerSize, staticSize = 0 + a::staticSize };
  typedef THIR_NAMESPACE::ValueSetter<
      Six::a,
      THIR_NAMESPACE::ValueSetter<THIR_NAMESPACE::__Last,
                                   THIR_NAMESPACE::__Last> >
      recursive;
  static recursive create();
};
struct Seven : THIR_NAMESPACE::Record<6 + 1, Seven> {
  struct a : Field<THIR_NAMESPACE::Plain<i32>, THIR_NAMESPACE::First> {};
  struct b : Field<THIR_NAMESPACE::VectorOfAny, a> {};
  enum {
    headerSize = 0 + a::headerSize + b::headerSize,
    staticSize = 0 + a::staticSize + b::staticSize
  };
  typedef THIR_NAMESPACE::ValueSetter<
      Seven::a,
      THIR_NAMESPACE::ValueSetter<
          Seven::b,
          THIR_NAMESPACE::ValueSetter<THIR_NAMESPACE::__Last,
                                       THIR_NAMESPACE::__Last> > >
      recursive;
  static recursive create();
};
struct Eight : THIR_NAMESPACE::Record<7 + 1, Eight> {
  struct a
      : Field<THIR_NAMESPACE::AnyOf<THIR_NAMESPACE::IDValidator<
                  Three::ID,
                  THIR_NAMESPACE::IDValidator<One::ID,
                                               THIR_NAMESPACE::__Last> > >,
              THIR_NAMESPACE::First> {};
  enum { headerSize = 0 + a::headerSize, staticSize = 0 + a::staticSize };
  typedef THIR_NAMESPACE::ValueSetter<
      Eight::a,
      THIR_NAMESPACE::ValueSetter<THIR_NAMESPACE::__Last,
                                   THIR_NAMESPACE::__Last> >
      recursive;
  static recursive create();
};
struct Nine : THIR_NAMESPACE::Record<8 + 1, Nine> {
  struct a
      : Field<THIR_NAMESPACE::VectorOfAnyOf<THIR_NAMESPACE::IDValidator<
                  Three::ID,
                  THIR_NAMESPACE::IDValidator<One::ID,
                                               THIR_NAMESPACE::__Last> > >,
              THIR_NAMESPACE::First> {};
  enum { headerSize = 0 + a::headerSize, staticSize = 0 + a::staticSize };
  typedef THIR_NAMESPACE::ValueSetter<
      Nine::a,
      THIR_NAMESPACE::ValueSetter<THIR_NAMESPACE::__Last,
                                   THIR_NAMESPACE::__Last> >
      recursive;
  static recursive create();
};
struct String : THIR_NAMESPACE::Record<9 + 1, String> {
  struct str : Field<THIR_NAMESPACE::Vector<char>, THIR_NAMESPACE::First> {};
  enum { headerSize = 0 + str::headerSize, staticSize = 0 + str::staticSize };
  typedef THIR_NAMESPACE::ValueSetter<
      String::str,
      THIR_NAMESPACE::ValueSetter<THIR_NAMESPACE::__Last,
                                   THIR_NAMESPACE::__Last> >
      recursive;
  static recursive create();
};
struct Rec : THIR_NAMESPACE::Record<10 + 1, Rec> {
  struct ids : Field<THIR_NAMESPACE::Vector<i64>, THIR_NAMESPACE::First> {};
  struct strings : Field<THIR_NAMESPACE::VectorOfAny, ids> {};
  enum {
    headerSize = 0 + ids::headerSize + strings::headerSize,
    staticSize = 0 + ids::staticSize + strings::staticSize
  };
  typedef THIR_NAMESPACE::ValueSetter<
      Rec::ids,
      THIR_NAMESPACE::ValueSetter<
          Rec::strings,
          THIR_NAMESPACE::ValueSetter<THIR_NAMESPACE::__Last,
                                       THIR_NAMESPACE::__Last> > >
      recursive;
  static recursive create();
};
One::recursive One::create() {
  THIR_NAMESPACE::SerializedData* sd = new THIR_NAMESPACE::SerializedData(
      sizeof(THIR_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(THIR_NAMESPACE::SerializedData::hel) + staticSize);
  THIR_NAMESPACE::RecordConstructor* rc =
      new THIR_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(THIR_NAMESPACE::RC(rc));
}
Two::recursive Two::create() {
  THIR_NAMESPACE::SerializedData* sd = new THIR_NAMESPACE::SerializedData(
      sizeof(THIR_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(THIR_NAMESPACE::SerializedData::hel) + staticSize);
  THIR_NAMESPACE::RecordConstructor* rc =
      new THIR_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(THIR_NAMESPACE::RC(rc));
}
Three::recursive Three::create() {
  THIR_NAMESPACE::SerializedData* sd = new THIR_NAMESPACE::SerializedData(
      sizeof(THIR_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(THIR_NAMESPACE::SerializedData::hel) + staticSize);
  THIR_NAMESPACE::RecordConstructor* rc =
      new THIR_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(THIR_NAMESPACE::RC(rc));
}
Four::recursive Four::create() {
  THIR_NAMESPACE::SerializedData* sd = new THIR_NAMESPACE::SerializedData(
      sizeof(THIR_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(THIR_NAMESPACE::SerializedData::hel) + staticSize);
  THIR_NAMESPACE::RecordConstructor* rc =
      new THIR_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(THIR_NAMESPACE::RC(rc));
}
Five::recursive Five::create() {
  THIR_NAMESPACE::SerializedData* sd = new THIR_NAMESPACE::SerializedData(
      sizeof(THIR_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(THIR_NAMESPACE::SerializedData::hel) + staticSize);
  THIR_NAMESPACE::RecordConstructor* rc =
      new THIR_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(THIR_NAMESPACE::RC(rc));
}
Six::recursive Six::create() {
  THIR_NAMESPACE::SerializedData* sd = new THIR_NAMESPACE::SerializedData(
      sizeof(THIR_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(THIR_NAMESPACE::SerializedData::hel) + staticSize);
  THIR_NAMESPACE::RecordConstructor* rc =
      new THIR_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(THIR_NAMESPACE::RC(rc));
}
Seven::recursive Seven::create() {
  THIR_NAMESPACE::SerializedData* sd = new THIR_NAMESPACE::SerializedData(
      sizeof(THIR_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(THIR_NAMESPACE::SerializedData::hel) + staticSize);
  THIR_NAMESPACE::RecordConstructor* rc =
      new THIR_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(THIR_NAMESPACE::RC(rc));
}
Eight::recursive Eight::create() {
  THIR_NAMESPACE::SerializedData* sd = new THIR_NAMESPACE::SerializedData(
      sizeof(THIR_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(THIR_NAMESPACE::SerializedData::hel) + staticSize);
  THIR_NAMESPACE::RecordConstructor* rc =
      new THIR_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(THIR_NAMESPACE::RC(rc));
}
Nine::recursive Nine::create() {
  THIR_NAMESPACE::SerializedData* sd = new THIR_NAMESPACE::SerializedData(
      sizeof(THIR_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(THIR_NAMESPACE::SerializedData::hel) + staticSize);
  THIR_NAMESPACE::RecordConstructor* rc =
      new THIR_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(THIR_NAMESPACE::RC(rc));
}
String::recursive String::create() {
  THIR_NAMESPACE::SerializedData* sd = new THIR_NAMESPACE::SerializedData(
      sizeof(THIR_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(THIR_NAMESPACE::SerializedData::hel) + staticSize);
  THIR_NAMESPACE::RecordConstructor* rc =
      new THIR_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(THIR_NAMESPACE::RC(rc));
}
Rec::recursive Rec::create() {
  THIR_NAMESPACE::SerializedData* sd = new THIR_NAMESPACE::SerializedData(
      sizeof(THIR_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(THIR_NAMESPACE::SerializedData::hel) + staticSize);
  THIR_NAMESPACE::RecordConstructor* rc =
      new THIR_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(THIR_NAMESPACE::RC(rc));
}
const size_t THIR_NAMESPACE::SerializedData::headerSizes[] = {
    0,
    One::headerSize,
    Two::headerSize,
    Three::headerSize,
    Four::headerSize,
    Five::headerSize,
    Six::headerSize,
    Seven::headerSize,
    Eight::headerSize,
    Nine::headerSize,
    String::headerSize,
    Rec::headerSize};
const size_t THIR_NAMESPACE::SerializedData::staticSizes[] = {
    0,
    One::staticSize,
    Two::staticSize,
    Three::staticSize,
    Four::staticSize,
    Five::staticSize,
    Six::staticSize,
    Seven::staticSize,
    Eight::staticSize,
    Nine::staticSize,
    String::staticSize,
    Rec::staticSize};
const size_t THIR_NAMESPACE::SerializedData::__LastType = Rec::ID;
