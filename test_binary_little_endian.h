#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

#include "structures.h"

using namespace Proto;

TEST(Binary, Simple)
{
    SerializedData *data = One::create().set(42).finish();
    ASSERT_EQ(data->vector(),
              std::vector<char>({
                  1, 0,             // ID
                 42, 0, 0, 0        // V
              }));
    delete data;
}

TEST(Binary, AnyOf)
{
    auto a = Eight::create();
    a.beginRecursive<Three>().set(3).finish().finish();
    auto data = a.next().finish();
    ASSERT_EQ(data->vector(),
              std::vector<char>({
                  8, 0,             // ID
                 10, 0, 0, 0,       // H1
                  3, 0,             // ID1
                  0, 0, 0, 0,       // H1.1
                  3, 0, 0, 0        // V1.1
              }));
    delete data;
}
