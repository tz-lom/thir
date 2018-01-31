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


//#include "tst_podtypes_struct.expanded.h"
#include "tst_podtypes_struct.h"

TEST(Simple, SimpleProtocol)
{
    SerializedData *data = One::create().set(42).finish();
    ASSERT_THAT(data->field<One::a>().value(), Eq(42));
    ASSERT_THAT(data->size(), Eq(2+4));

    //ASSERT_THROW(data->field<Two::a>(), WrongType);
    delete data;
}
/*
TEST(Vector, SimpleProtocol)
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


TEST(Vector_std, SimpleProtocol)
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

TEST(Vector_combine_plain_and_std, SimpleProtocol)
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
    delete data;
}

TEST(Any, SimpleProtocol)
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

TEST(IncompleteCreation, SimpleProtocol)
{
    auto a = Five::create();
    auto b = a.beginRecursive<Three>()
            .set(42);
    ASSERT_THROW(a.next(), WrongCreationOrder);
    //b.cancelCreation();
    //delete data;
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
