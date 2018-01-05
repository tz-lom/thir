#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

//#include "tst_podtypes_struct.expanded.h"
#include "tst_podtypes_struct.h"

TEST(PODTypes, SimpleProtocol)
{
    SerializedData *data = PODcontainer::create().set(42).set(0xFFFFFFFF).finish();
    ASSERT_THAT(data->extractField<PODcontainer::I8>(), Eq(42));
    ASSERT_THAT(data->extractField<PODcontainer::U64>(), Eq(0xFFFFFFFF));
    ASSERT_THAT(data->size(), Eq(2+1+8));

    ASSERT_THROW(data->extractField<OneBool::B>(), WrongType);
}

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
