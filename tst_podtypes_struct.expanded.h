

struct One : PROTO_NAMESPACE::Record<0 + 1, One> {
  struct a : Field<PROTO_NAMESPACE::Plain<i32>, PROTO_NAMESPACE::First> {};
  enum { headerSize = 0 + a::headerSize, staticSize = 0 + a::staticSize };
  typedef PROTO_NAMESPACE::ValueSetter<
      One::a,
      PROTO_NAMESPACE::ValueSetter<PROTO_NAMESPACE::__Last,
                                   PROTO_NAMESPACE::__Last> >
      recursive;
  static recursive create();
};
struct Two : PROTO_NAMESPACE::Record<1 + 1, Two> {
  struct a : Field<PROTO_NAMESPACE::Plain<i32>, PROTO_NAMESPACE::First> {};
  struct b : Field<PROTO_NAMESPACE::Plain<f64>, a> {};
  enum {
    headerSize = 0 + a::headerSize + b::headerSize,
    staticSize = 0 + a::staticSize + b::staticSize
  };
  typedef PROTO_NAMESPACE::ValueSetter<
      Two::a,
      PROTO_NAMESPACE::ValueSetter<
          Two::b,
          PROTO_NAMESPACE::ValueSetter<PROTO_NAMESPACE::__Last,
                                       PROTO_NAMESPACE::__Last> > >
      recursive;
  static recursive create();
};
struct Three : PROTO_NAMESPACE::Record<2 + 1, Three> {
  struct a : Field<PROTO_NAMESPACE::Plain<i32>, PROTO_NAMESPACE::First> {};
  struct b : Field<PROTO_NAMESPACE::Vector<i16>, a> {};
  enum {
    headerSize = 0 + a::headerSize + b::headerSize,
    staticSize = 0 + a::staticSize + b::staticSize
  };
  typedef PROTO_NAMESPACE::ValueSetter<
      Three::a,
      PROTO_NAMESPACE::ValueSetter<
          Three::b,
          PROTO_NAMESPACE::ValueSetter<PROTO_NAMESPACE::__Last,
                                       PROTO_NAMESPACE::__Last> > >
      recursive;
  static recursive create();
};
struct Four : PROTO_NAMESPACE::Record<3 + 1, Four> {
  struct __void : Field<PROTO_NAMESPACE::Void, PROTO_NAMESPACE::First> {};
  enum {
    headerSize = 0 + __void::headerSize,
    staticSize = 0 + __void::staticSize
  };
  typedef PROTO_NAMESPACE::ValueSetter<
      Four::__void,
      PROTO_NAMESPACE::ValueSetter<PROTO_NAMESPACE::__Last,
                                   PROTO_NAMESPACE::__Last> >
      recursive;
  static recursive create();
};
struct Five : PROTO_NAMESPACE::Record<4 + 1, Five> {
  struct a : Field<PROTO_NAMESPACE::Any, PROTO_NAMESPACE::First> {};
  struct b : Field<PROTO_NAMESPACE::Any, a> {};
  enum {
    headerSize = 0 + a::headerSize + b::headerSize,
    staticSize = 0 + a::staticSize + b::staticSize
  };
  typedef PROTO_NAMESPACE::ValueSetter<
      Five::a,
      PROTO_NAMESPACE::ValueSetter<
          Five::b,
          PROTO_NAMESPACE::ValueSetter<PROTO_NAMESPACE::__Last,
                                       PROTO_NAMESPACE::__Last> > >
      recursive;
  static recursive create();
};
struct Six : PROTO_NAMESPACE::Record<5 + 1, Six> {
  struct a : Field<PROTO_NAMESPACE::VectorOfAny, PROTO_NAMESPACE::First> {};
  enum { headerSize = 0 + a::headerSize, staticSize = 0 + a::staticSize };
  typedef PROTO_NAMESPACE::ValueSetter<
      Six::a,
      PROTO_NAMESPACE::ValueSetter<PROTO_NAMESPACE::__Last,
                                   PROTO_NAMESPACE::__Last> >
      recursive;
  static recursive create();
};
struct Seven : PROTO_NAMESPACE::Record<6 + 1, Seven> {
  struct a : Field<PROTO_NAMESPACE::Plain<i32>, PROTO_NAMESPACE::First> {};
  struct b : Field<PROTO_NAMESPACE::VectorOfAny, a> {};
  enum {
    headerSize = 0 + a::headerSize + b::headerSize,
    staticSize = 0 + a::staticSize + b::staticSize
  };
  typedef PROTO_NAMESPACE::ValueSetter<
      Seven::a,
      PROTO_NAMESPACE::ValueSetter<
          Seven::b,
          PROTO_NAMESPACE::ValueSetter<PROTO_NAMESPACE::__Last,
                                       PROTO_NAMESPACE::__Last> > >
      recursive;
  static recursive create();
};
struct Eight : PROTO_NAMESPACE::Record<7 + 1, Eight> {
  struct a
      : Field<PROTO_NAMESPACE::AnyOf<PROTO_NAMESPACE::IDValidator<
                  Three::ID,
                  PROTO_NAMESPACE::IDValidator<One::ID,
                                               PROTO_NAMESPACE::__Last> > >,
              PROTO_NAMESPACE::First> {};
  enum { headerSize = 0 + a::headerSize, staticSize = 0 + a::staticSize };
  typedef PROTO_NAMESPACE::ValueSetter<
      Eight::a,
      PROTO_NAMESPACE::ValueSetter<PROTO_NAMESPACE::__Last,
                                   PROTO_NAMESPACE::__Last> >
      recursive;
  static recursive create();
};
struct Nine : PROTO_NAMESPACE::Record<8 + 1, Nine> {
  struct a
      : Field<PROTO_NAMESPACE::VectorOfAnyOf<PROTO_NAMESPACE::IDValidator<
                  Three::ID,
                  PROTO_NAMESPACE::IDValidator<One::ID,
                                               PROTO_NAMESPACE::__Last> > >,
              PROTO_NAMESPACE::First> {};
  enum { headerSize = 0 + a::headerSize, staticSize = 0 + a::staticSize };
  typedef PROTO_NAMESPACE::ValueSetter<
      Nine::a,
      PROTO_NAMESPACE::ValueSetter<PROTO_NAMESPACE::__Last,
                                   PROTO_NAMESPACE::__Last> >
      recursive;
  static recursive create();
};
struct String : PROTO_NAMESPACE::Record<9 + 1, String> {
  struct str : Field<PROTO_NAMESPACE::Vector<char>, PROTO_NAMESPACE::First> {};
  enum { headerSize = 0 + str::headerSize, staticSize = 0 + str::staticSize };
  typedef PROTO_NAMESPACE::ValueSetter<
      String::str,
      PROTO_NAMESPACE::ValueSetter<PROTO_NAMESPACE::__Last,
                                   PROTO_NAMESPACE::__Last> >
      recursive;
  static recursive create();
};
struct Rec : PROTO_NAMESPACE::Record<10 + 1, Rec> {
  struct ids : Field<PROTO_NAMESPACE::Vector<i64>, PROTO_NAMESPACE::First> {};
  struct strings : Field<PROTO_NAMESPACE::VectorOfAny, ids> {};
  enum {
    headerSize = 0 + ids::headerSize + strings::headerSize,
    staticSize = 0 + ids::staticSize + strings::staticSize
  };
  typedef PROTO_NAMESPACE::ValueSetter<
      Rec::ids,
      PROTO_NAMESPACE::ValueSetter<
          Rec::strings,
          PROTO_NAMESPACE::ValueSetter<PROTO_NAMESPACE::__Last,
                                       PROTO_NAMESPACE::__Last> > >
      recursive;
  static recursive create();
};
One::recursive One::create() {
  PROTO_NAMESPACE::SerializedData* sd = new PROTO_NAMESPACE::SerializedData(
      sizeof(PROTO_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(PROTO_NAMESPACE::SerializedData::hel) + staticSize);
  PROTO_NAMESPACE::RecordConstructor* rc =
      new PROTO_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(PROTO_NAMESPACE::RC(rc));
}
Two::recursive Two::create() {
  PROTO_NAMESPACE::SerializedData* sd = new PROTO_NAMESPACE::SerializedData(
      sizeof(PROTO_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(PROTO_NAMESPACE::SerializedData::hel) + staticSize);
  PROTO_NAMESPACE::RecordConstructor* rc =
      new PROTO_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(PROTO_NAMESPACE::RC(rc));
}
Three::recursive Three::create() {
  PROTO_NAMESPACE::SerializedData* sd = new PROTO_NAMESPACE::SerializedData(
      sizeof(PROTO_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(PROTO_NAMESPACE::SerializedData::hel) + staticSize);
  PROTO_NAMESPACE::RecordConstructor* rc =
      new PROTO_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(PROTO_NAMESPACE::RC(rc));
}
Four::recursive Four::create() {
  PROTO_NAMESPACE::SerializedData* sd = new PROTO_NAMESPACE::SerializedData(
      sizeof(PROTO_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(PROTO_NAMESPACE::SerializedData::hel) + staticSize);
  PROTO_NAMESPACE::RecordConstructor* rc =
      new PROTO_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(PROTO_NAMESPACE::RC(rc));
}
Five::recursive Five::create() {
  PROTO_NAMESPACE::SerializedData* sd = new PROTO_NAMESPACE::SerializedData(
      sizeof(PROTO_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(PROTO_NAMESPACE::SerializedData::hel) + staticSize);
  PROTO_NAMESPACE::RecordConstructor* rc =
      new PROTO_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(PROTO_NAMESPACE::RC(rc));
}
Six::recursive Six::create() {
  PROTO_NAMESPACE::SerializedData* sd = new PROTO_NAMESPACE::SerializedData(
      sizeof(PROTO_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(PROTO_NAMESPACE::SerializedData::hel) + staticSize);
  PROTO_NAMESPACE::RecordConstructor* rc =
      new PROTO_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(PROTO_NAMESPACE::RC(rc));
}
Seven::recursive Seven::create() {
  PROTO_NAMESPACE::SerializedData* sd = new PROTO_NAMESPACE::SerializedData(
      sizeof(PROTO_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(PROTO_NAMESPACE::SerializedData::hel) + staticSize);
  PROTO_NAMESPACE::RecordConstructor* rc =
      new PROTO_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(PROTO_NAMESPACE::RC(rc));
}
Eight::recursive Eight::create() {
  PROTO_NAMESPACE::SerializedData* sd = new PROTO_NAMESPACE::SerializedData(
      sizeof(PROTO_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(PROTO_NAMESPACE::SerializedData::hel) + staticSize);
  PROTO_NAMESPACE::RecordConstructor* rc =
      new PROTO_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(PROTO_NAMESPACE::RC(rc));
}
Nine::recursive Nine::create() {
  PROTO_NAMESPACE::SerializedData* sd = new PROTO_NAMESPACE::SerializedData(
      sizeof(PROTO_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(PROTO_NAMESPACE::SerializedData::hel) + staticSize);
  PROTO_NAMESPACE::RecordConstructor* rc =
      new PROTO_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(PROTO_NAMESPACE::RC(rc));
}
String::recursive String::create() {
  PROTO_NAMESPACE::SerializedData* sd = new PROTO_NAMESPACE::SerializedData(
      sizeof(PROTO_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(PROTO_NAMESPACE::SerializedData::hel) + staticSize);
  PROTO_NAMESPACE::RecordConstructor* rc =
      new PROTO_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(PROTO_NAMESPACE::RC(rc));
}
Rec::recursive Rec::create() {
  PROTO_NAMESPACE::SerializedData* sd = new PROTO_NAMESPACE::SerializedData(
      sizeof(PROTO_NAMESPACE::SerializedData::rid) +
      headerSize * sizeof(PROTO_NAMESPACE::SerializedData::hel) + staticSize);
  PROTO_NAMESPACE::RecordConstructor* rc =
      new PROTO_NAMESPACE::RecordConstructor(sd);
  rc->beginNested(ID, staticSize, headerSize, {0, 0});
  return recursive(PROTO_NAMESPACE::RC(rc));
}
const size_t PROTO_NAMESPACE::SerializedData::headerSizes[] = {
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
const size_t PROTO_NAMESPACE::SerializedData::staticSizes[] = {
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
const size_t PROTO_NAMESPACE::SerializedData::__LastType = Rec::ID;
