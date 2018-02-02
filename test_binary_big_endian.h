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
                  0, 1,             // ID
                  0, 0, 0, 42        // V
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
                  0, 8,             // ID
                  0, 0, 0, 10,       // H1
                  0, 3,             // ID1
                  0, 0, 0, 0,       // H1.1
                  0, 0, 0, 3        // V1.1
              }));
    delete data;
}
