#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

#include "structures.h"

using namespace Thir;

TEST(Binary, Simple)
{
    const char binary[] =
            "\x01\x00"
            "\x2A\x00\x00\x00";

    SD data = One::create().set(42).finish();
    ASSERT_EQ(data->vector(),
              std::vector<char>(&binary[0], &binary[sizeof(binary)-1]));
}

TEST(Binary, AnyOf)
{
    const char binary[] =
            "\x08\x00"
            "\x0A\x00\x00\x00"
            "\x03\x00"
            "\x00\x00\x00\x00"
            "\x03\x00\x00\x00";

    Eight::recursive a = Eight::create();
    a.beginRecursive<Three>().set(3).finish().finish();
    SD data = a.next().finish();

    ASSERT_EQ(data->vector(),
              std::vector<char>(&binary[0], &binary[sizeof(binary)-1]));
}

TEST(Binary, Empty)
{
    const char binary[] =
            "\x0A\x00"
            ;

    SD data = Ten::create().next().finish();

    ASSERT_EQ(data->vector(),
              std::vector<char>(&binary[0], &binary[sizeof(binary)-1]));
}
/*
TEST(Binary, Vector)
{
    auto data = Three::create().set(42).add(128).add(-15754).add(16200).finish().finish();
    ASSERT_EQ(data->vector(),
              std::vector<char>({
                  3, 0,
                  6, 0,
                  42, 0, 0, 0,
                  0x80, 0x00,
                  0x76, 0xC2,
                  0x48, 0x3F
              }));
    delete data;
}*/
