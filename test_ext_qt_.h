#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

#define THIR_EXTENSIONS (Qt)

//#define PRECOMPILED
#ifdef PRECOMPILED
#  include "structures.expanded.h"
#else
#  include "structures.h"
#endif

using namespace Thir;


TEST(Qt, QString)
{
    QString str = "Foo bar\0baz";
    SD data = Eleven::create().set(str).finish();

    ASSERT_EQ((QString)data->field<Eleven::a>(), str);
}
