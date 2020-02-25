#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

#include "structures.h"

using namespace Thir;

#define ASSERT_BINARY(what, binary)\
    ASSERT_EQ(what, std::vector<char>(&binary[0], &binary[sizeof(binary)-1]))

TEST(Binary, Simple)
{
    const char binary[] =
            "\x00\x01"
            "\x00\x00\x00\x2A";

    SD data = One::create().set(42).finish();
    
    ASSERT_BINARY(data->vector(), binary);
}

TEST(Binary, AnyOf)
{
    const char binary[] =
            "\x00\x08"
            "\x00\x00\x00\x0A"
            "\x00\x03"
            "\x00\x00\x00\x00"
            "\x00\x00\x00\x03";

    Eight::recursive a = Eight::create();
    a.beginRecursive<Three>().set(3).finish().finish();
    SD data = a.next().finish();

    ASSERT_BINARY(data->vector(), binary);
}

TEST(Binary, Empty)
{
    const char binary[] =
            "\x00\x0A"
            ;

    SD data = Ten::create().next().finish();

    ASSERT_BINARY(data->vector(), binary);
}

TEST(Binary, R01)
{
    
}

