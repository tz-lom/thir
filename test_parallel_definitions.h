#include <gtest/gtest.h>

using namespace testing;

#include "structures.h"

#define SECOND_DEFINITION \
    RECORD(Foo, \
        FIELD(a, int8_t) \
    )\
    RECORD(Bar, \
        FIELD(a, bool) \
    )

#undef PROTO_NAMESPACE
#define PROTO_NAMESPACE Parallel

#include "protocol/classes.h"
#include "protocol/fields/all.h"
#include "protocol/classes.imp.h"
#include "generate.h"
GENERATE_HEADER(SECOND_DEFINITION)
GENERATE_IMPLEMENTATION(SECOND_DEFINITION)
#include "generate_undef.h"

#undef PROTO_NAMESPACE

TEST(Paralel, BothDefinitions)
{
    auto data_a = One::create().set(42).finish();
    auto data_b = Foo::create().set(-112).finish();

    ASSERT_EQ(data_a->field<One::a>().value(), 42);
    ASSERT_EQ(data_b->field<Foo::a>().value(), -112);

    delete data_a;
    delete data_b;
}
