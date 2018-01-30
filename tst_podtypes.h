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

TEST(PODTypes, SimpleProtocol)
{
    SerializedData *data = One::create().set(42).finish();
    ASSERT_THAT(data->field<One::a>().value(), Eq(42));
    ASSERT_THAT(data->size(), Eq(2+4));

    //ASSERT_THROW(data->field<OneBool::B>(), WrongType);
}
/*
TEST(PODVector, SimpleProtocol)
{
    PodVector::recursive rec = PodVector::createRecursive();
    SerializedData *data = rec.add(1).add(2).add(3).finish().finish();
    ASSERT_EQ(data->extractVector<PodVector::vals>().size(), 3);
    ASSERT_EQ(data->extractVector<PodVector::vals>()[0], 1);
    ASSERT_EQ(data->extractVector<PodVector::vals>()[1], 2);
    ASSERT_EQ(data->extractVector<PodVector::vals>()[2], 3);
}

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
