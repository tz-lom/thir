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

#undef THIR_NAMESPACE
#define THIR_NAMESPACE (Parallel)

#include <thir/generate.h>
#include <thir/classes.h>
#include <thir/fields/all.h>
#include <thir/classes.imp.h>
THIR_GENERATE_HEADER(SECOND_DEFINITION)
THIR_GENERATE_IMPLEMENTATION(SECOND_DEFINITION)

#include <thir/undef.h>

#undef THIR_NAMESPACE

TEST(Paralel, BothDefinitions)
{
    Thir::SD data_a = One::create().set(42).finish();
    Parallel::SD data_b = Foo::create().set(-112).finish();

    ASSERT_EQ(data_a->field<One::a>().value(), 42);
    ASSERT_EQ(data_b->field<Foo::a>().value(), -112);
}
