#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

#include "structures.h"

using namespace Thir;

TEST(Binary, Simple)
{
    const char binary[] =
            "\x00\x01"
            "\x00\x00\x00\x2A";

    SerializedData* data = One::create().set(42).finish();
    ASSERT_EQ(data->vector(),
              std::vector<char>(&binary[0], &binary[sizeof(binary)-1]));
    delete data;
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
    SerializedData* data = a.next().finish();

    ASSERT_EQ(data->vector(),
              std::vector<char>(&binary[0], &binary[sizeof(binary)-1]));
    delete data;
}

TEST(Binary, Empty)
{
    const char binary[] =
            "\x00\x0A"
            ;

    SerializedData* data = Ten::create().next().finish();

    ASSERT_EQ(data->vector(),
              std::vector<char>(&binary[0], &binary[sizeof(binary)-1]));
    delete data;
}
