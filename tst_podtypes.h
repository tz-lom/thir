#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;


#include "protocol/classes.h"
#include "protocol/classes.imp.h"
#include "protocol/fields/all.h"

typedef uint64_t u64;
typedef uint32_t u32;
typedef int64_t  i64;
typedef int32_t  i32;
typedef float    f32;
typedef double   f64;
typedef uint16_t u16;
typedef int16_t  i16;
typedef uint8_t  u8;
typedef int8_t   i8;

//#define PRECOMPILED
#ifdef PRECOMPILED
#  include "tst_podtypes_struct.expanded.h"
#else
#  include "tst_podtypes_struct.h"
#endif

using namespace Proto;

TEST(Creation, Simple)
{
    Proto::RecordConstructor *rc = new Proto::RecordConstructor(0);

    RC a(rc);

    SerializedData *data = One::create().set(42).finish();
    ASSERT_THAT(data->field<One::a>().value(), Eq(42));
    ASSERT_THAT(data->size(), Eq(2+4));

    ASSERT_THROW(data->field<Two::a>(), WrongType);
    delete data;
}

TEST(Creation, Vector)
{
    auto data = Three::create().set(12).add(42).add(24).add(77).finish().finish();
    ASSERT_EQ(data->field<Three::a>().value(), 12);
    ASSERT_EQ(data->field<Three::b>().size(), 3);
    ASSERT_EQ(data->field<Three::b>().get(0), 42);
    ASSERT_EQ(data->field<Three::b>().get(1), 24);
    ASSERT_EQ(data->field<Three::b>().get(2), 77);

    ASSERT_THAT(data->size(), Eq(2+4+4+2*3));
    delete data;
}


TEST(Creation, Vector_std)
{
    std::vector<i16> source({42,24,77});
    auto data = Three::create().set(12).addVector(source).finish().finish();
    ASSERT_EQ(data->field<Three::a>().value(), 12);
    ASSERT_EQ(data->field<Three::b>().size(), 3);
    ASSERT_EQ(data->field<Three::b>().get(0), 42);
    ASSERT_EQ(data->field<Three::b>().get(1), 24);
    ASSERT_EQ(data->field<Three::b>().get(2), 77);
    std::vector<i16> result = data->field<Three::b>();
    ASSERT_EQ(result, source);

    ASSERT_THAT(data->size(), Eq(2+4+4+2*3));
    delete data;
}

TEST(Creation, Vector_combine_plain_and_std)
{
    std::vector<i16> source({42,24,77});
    auto data = Three::create()
            .set(12)
                .addVector(source)
                .add(11)
                .addVector(source)
            .finish()
            .finish();
    ASSERT_EQ(data->field<Three::a>().value(), 12);
    ASSERT_EQ(data->field<Three::b>().size(), 7);
    std::vector<i16> result = data->field<Three::b>();
    ASSERT_EQ(result, std::vector<i16>({42, 24, 77, 11, 42, 24, 77}));

    ASSERT_EQ(data->size(), 2+4+4+2*7);
    delete data;template
}

TEST(Creation, Any)
{
    auto a = Five::create();
    a.beginRecursive<One>().set(42).finish();
    auto data = a.next()
            .next()
            .finish();

    ASSERT_EQ(data->field<Five::a>().field<One::a>().value(), 42);
    ASSERT_EQ(data->field<Five::b>().value().id(), 0);
    ASSERT_EQ(data->field<Five::b>().value().size(), 0);

    ASSERT_EQ(data->size(), 2+4+4+2+4);

    delete data;
}

TEST(IncorrectCreation, DoubleInitializeAny)
{
    auto a = Five::create();
    auto b = a.beginRecursive<Three>()
            .set(42);
    ASSERT_THROW(a.next(), WrongCreationOrder);
    b.cancelCreation(); // prevent leakage
}

TEST(Creation, VectorOfAny)
{
    auto a = Six::create();
    a.add<One>().set(10).finish();
    a.add<Two>().set(11).set(12).finish();
    auto data = a.finish().finish();

    auto sz = data->field<Six::a>().size();
    ASSERT_EQ(sz, 2);
    ASSERT_EQ(data->field<Six::a>().get(0).field<One::a>().value(), 10);
    ASSERT_EQ(data->field<Six::a>().get(1).field<Two::a>().value(), 11);
    ASSERT_EQ(data->field<Six::a>().get(1).field<Two::b>().value(), 12);

    delete data;
}


TEST(IncorrectCreation, DoubleInitializationField)
{
    auto a = Seven::create();
    auto b = a.set(42);
    ASSERT_THROW(a.set(12), WrongCreationOrder);
    b.add<One>().set(10).finish();
    b.add<Two>().set(11).set(12).finish();
    ASSERT_THROW(a.set(1), WrongCreationOrder);
    auto data = b.finish().finish();

    ASSERT_EQ(data->field<Seven::a>().value(), 42);
    ASSERT_EQ(data->field<Seven::b>().get(0).field<One::a>().value(), 10);
    ASSERT_EQ(data->field<Seven::b>().get(1).field<Two::a>().value(), 11);
    ASSERT_EQ(data->field<Seven::b>().get(1).field<Two::b>().value(), 12);

    delete data;
}

TEST(IncorrectCreation, DelayedDoubleInitializationOfPlain)
{
    auto a = Seven::create();
    auto b = a.set(42);
    ASSERT_THROW(a.set(12), WrongCreationOrder);
    auto c = b.add<One>();
    c.set(10).finish();
    ASSERT_THROW(c.set(1), WrongCreationOrder);
    auto d = b.add<Two>();
    ASSERT_THROW(c.set(1), WrongCreationOrder);
    d.set(11).set(12).finish();
    ASSERT_THROW(a.set(1), WrongCreationOrder);
    auto data = b.finish().finish();

    ASSERT_EQ(data->field<Seven::a>().value(), 42);
    ASSERT_EQ(data->field<Seven::b>().get(0).field<One::a>().value(), 10);
    ASSERT_EQ(data->field<Seven::b>().get(1).field<Two::a>().value(), 11);
    ASSERT_EQ(data->field<Seven::b>().get(1).field<Two::b>().value(), 12);

    delete data;
}

TEST(IncorrectCreation, CreationOfAnyWhenPreviouseIsIncomplete)
{
    auto a = Six::create();
    auto b = a.add<One>();
    ASSERT_THROW(a.add<One>(), WrongCreationOrder);
    b.set(10).finish();
    ASSERT_NO_THROW(a.add<One>().set(10).finish());
    auto data = a.finish().finish();

    ASSERT_EQ(data->field<Six::a>().size(), 2);
    ASSERT_EQ(data->field<Six::a>().get(0).field<One::a>().value(), 10);
    ASSERT_EQ(data->field<Six::a>().get(1).field<One::a>().value(), 10);

    delete data;
}

TEST(Creation, AnyOf)
{
    auto a = Eight::create();

    ASSERT_NO_THROW(a.beginRecursive<One>().set(2).finish());
    delete a.next().finish();


    auto b = Eight::create();
    ASSERT_THROW( b.beginRecursive<Two>().set(2).set(3).finish(), WrongType);
    ASSERT_NO_THROW(b.beginRecursive<Three>().set(3).finish().finish());
    auto data = b.next().finish();
    ASSERT_EQ(data->field<Eight::a>().field<Three::a>().value(), 3);
    ASSERT_EQ(data->field<Eight::a>().field<Three::b>().size(), 0);
    ASSERT_EQ(data->vector(), std::vector<char>({
                  8, 0,             // ID
                 10, 0, 0, 0,       // H1
                  3, 0,              // ID
                  0, 0, 0, 0,       // H1.1
                  3, 0, 0, 0        //V1
              }));

    delete data;
}

/*
TEST(AnyVector, SimpleProtocol)
{
    auto rec = AVector::create();
    rec.begin<String>().set("Foo").finish();
    rec.begin<String>().set("bar").finish();
    SerializedData *data = rec.finish().finish();

    ASSERT_EQ(data->extractAnyVector<AVector::str>().size(), 2);
    ASSERT_EQ(data->extractAnyVectorElement<AVector::str>(0).extractString<String::str>(), "Foo");
    //ASSERT_EQ(data->extractAnyVectorElement<AVector::str>(1).extractString<String::str>(), "bar");
    //std::cout << data->extractAnyVectorElement<AVector::str>(1).size();
}
*/
