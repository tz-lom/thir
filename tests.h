#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;


//#define PRECOMPILED
#ifdef PRECOMPILED
#  include "structures.expanded.h"
#else
#  include "structures.h"
#endif

using namespace Thir;

TEST(Creation, Simple)
{
    SD data = One::create().set(42).finish();
    ASSERT_THAT(data->field<One::a>().value(), Eq(42));
    ASSERT_THAT(data->size(), Eq(2+4));

    ASSERT_THROW(data->field<Two::a>(), WrongType);
}

TEST(Creation, Vector)
{
    SD data = Three::create()
            .set(12)
            .add(42)
            .add(24)
            .add(77)
            .finish()
            .finish();
    ASSERT_EQ(data->field<Three::a>().value(), 12);
    ASSERT_EQ(data->field<Three::b>().size(), 3);
    ASSERT_EQ(data->field<Three::b>().get(0), 42);
    ASSERT_EQ(data->field<Three::b>().get(1), 24);
    ASSERT_EQ(data->field<Three::b>().get(2), 77);

    ASSERT_THAT(data->size(), Eq(2+4+4+2*3));
}


TEST(Creation, Vector_std)
{
    i16 sourceData[] = {42,24,77};
    std::vector<i16> source(&sourceData[0], &sourceData[sizeof(sourceData)/sizeof(sourceData[0])]);

    SD data = Three::create().set(12).addVector(source).finish().finish();
    ASSERT_EQ(data->field<Three::a>().value(), 12);
    ASSERT_EQ(data->field<Three::b>().size(), 3);
    ASSERT_EQ(data->field<Three::b>().get(0), 42);
    ASSERT_EQ(data->field<Three::b>().get(1), 24);
    ASSERT_EQ(data->field<Three::b>().get(2), 77);
    std::vector<i16> result = data->field<Three::b>();
    ASSERT_EQ(result, source);

    ASSERT_THAT(data->size(), Eq(2+4+4+2*3));
}

TEST(Creation, Vector_combine_plain_and_std)
{
    i16 sourceData[] = {42,24,77};
    std::vector<i16> source(&sourceData[0], &sourceData[sizeof(sourceData)/sizeof(sourceData[0])]);

    SD data = Three::create()
            .set(12)
                .addVector(source)
                .add(11)
                .addVector(source)
            .finish()
            .finish();
    ASSERT_EQ(data->field<Three::a>().value(), 12);
    ASSERT_EQ(data->field<Three::b>().size(), 7);



    i16 resultData[] = {42, 24, 77, 11, 42, 24, 77};
    std::vector<i16> result(&resultData[0], &resultData[sizeof(resultData)/sizeof(resultData[0])]);

    ASSERT_EQ( (::std::vector<i16>)data->field<Three::b>(), result);

    ASSERT_EQ(data->size(), 2+4+4+2*7);
}

TEST(Creation, Any)
{
    Five::recursive a = Five::create();
    a.beginRecursive<One>().set(42).finish();
    SD data = a.next()
            .next()
            .finish();

    ASSERT_EQ(data->field<Five::a>().field<One::a>().value(), 42);
    ASSERT_EQ(data->field<Five::b>().value().id(), 0);
    ASSERT_EQ(data->field<Five::b>().value().size(), 0);

    ASSERT_EQ(data->size(), 2+4+4+2+4);
}

TEST(IncorrectCreation, DoubleInitializeAny)
{
    Five::recursive a = Five::create();
    Three::recursive::N b = a.beginRecursive<Three>()
            .set(42);
    ASSERT_THROW(a.next(), WrongCreationOrder);
    //b.cancelCreation(); // prevent leakage
}

TEST(Creation, VectorOfAny)
{
    Six::recursive a = Six::create();
    a.add<One>().set(10).finish();
    a.add<Two>().set(11).set(12).finish();
    SD data = a.finish().finish();

    size_t sz = data->field<Six::a>().size();
    ASSERT_EQ(sz, 2);
    ASSERT_EQ(data->field<Six::a>().get(0).field<One::a>().value(), 10);
    ASSERT_EQ(data->field<Six::a>().get(1).field<Two::a>().value(), 11);
    ASSERT_EQ(data->field<Six::a>().get(1).field<Two::b>().value(), 12);
}


TEST(IncorrectCreation, DoubleInitializationField)
{
    Seven::recursive a = Seven::create();
    Seven::recursive::N b = a.set(42);
    ASSERT_THROW(a.set(12), WrongCreationOrder);
    b.add<One>().set(10).finish();
    b.add<Two>().set(11).set(12).finish();
    ASSERT_THROW(a.set(1), WrongCreationOrder);
    SD data = b.finish().finish();

    ASSERT_EQ(data->field<Seven::a>().value(), 42);
    ASSERT_EQ(data->field<Seven::b>().get(0).field<One::a>().value(), 10);
    ASSERT_EQ(data->field<Seven::b>().get(1).field<Two::a>().value(), 11);
    ASSERT_EQ(data->field<Seven::b>().get(1).field<Two::b>().value(), 12);
}

TEST(IncorrectCreation, DelayedDoubleInitializationOfPlain)
{
    Seven::recursive a = Seven::create();
    Seven::recursive::N b = a.set(42);
    ASSERT_THROW(a.set(12), WrongCreationOrder);
    One::recursive c = b.add<One>();
    c.set(10).finish();
    ASSERT_THROW(c.set(1), WrongCreationOrder);
    Two::recursive d = b.add<Two>();
    ASSERT_THROW(c.set(1), WrongCreationOrder);
    d.set(11).set(12).finish();
    ASSERT_THROW(a.set(1), WrongCreationOrder);
    SD data = b.finish().finish();

    ASSERT_EQ(data->field<Seven::a>().value(), 42);
    ASSERT_EQ(data->field<Seven::b>().get(0).field<One::a>().value(), 10);
    ASSERT_EQ(data->field<Seven::b>().get(1).field<Two::a>().value(), 11);
    ASSERT_EQ(data->field<Seven::b>().get(1).field<Two::b>().value(), 12);
}

TEST(IncorrectCreation, CreationOfAnyWhenPreviouseIsIncomplete)
{
    Six::recursive a = Six::create();
    One::recursive b = a.add<One>();
    ASSERT_THROW(a.add<One>(), WrongCreationOrder);
    b.set(10).finish();
    ASSERT_NO_THROW(a.add<One>().set(10).finish());
    SD data = a.finish().finish();

    ASSERT_EQ(data->field<Six::a>().size(), 2);
    ASSERT_EQ(data->field<Six::a>().get(0).field<One::a>().value(), 10);
    ASSERT_EQ(data->field<Six::a>().get(1).field<One::a>().value(), 10);
}

TEST(Creation, AnyOf)
{
    Eight::recursive a = Eight::create();

    ASSERT_NO_THROW(a.beginRecursive<One>().set(2).finish());
    a.next().finish();


    Eight::recursive b = Eight::create();
    ASSERT_THROW( b.beginRecursive<Two>().set(2).set(3).finish(), WrongType);
    ASSERT_NO_THROW(b.beginRecursive<Three>().set(3).finish().finish());
    SD data = b.next().finish();
    ASSERT_EQ(data->field<Eight::a>().field<Three::a>().value(), 3);
    ASSERT_EQ(data->field<Eight::a>().field<Three::b>().size(), 0);
}

TEST(Creation, VectorOfAnyOf)
{
    Nine::recursive a = Nine::create();
    ASSERT_NO_THROW( a.add<One>().set(2).finish() );
    ASSERT_THROW( a.add<Two>().set(2).set(3).finish(), WrongType);
    ASSERT_NO_THROW( a.add<Three>().set(3).finish().finish() );

    SD data = a.finish().finish();
    ASSERT_EQ(data->field<Nine::a>().size(), 2);
    ASSERT_EQ(data->field<Nine::a>().get(0).field<One::a>().value(), 2);
    ASSERT_EQ(data->field<Nine::a>().get(1).field<Three::a>().value(), 3);
    ASSERT_EQ(data->field<Nine::a>().get(1).field<Three::b>().size(), 0);
}

TEST(Creation, Empty)
{
    SD data = Ten::create().next().finish();
    ASSERT_EQ(data->id(), Ten::ID);
}

