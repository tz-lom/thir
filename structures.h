#ifndef TESTS_MAIN_STRUCTURES
#define TESTS_MAIN_STRUCTURES


#include <thir/generate.h>
#include <thir/classes.h>
#include <thir/fields/all.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef int64_t  i64;
typedef int32_t  i32;
typedef float    f32;
typedef double   f64;
typedef uint16_t u16;
typedef int16_t  i16;
typedef uint8_t  u8;
typedef int8_t   i8;

#define MAIN_DEFINITION \
    RECORD(One, \
        FIELD(a, i32) \
    )\
    RECORD(Two, \
        FIELD(a, i32) \
        FIELD(b, f64) \
    )\
    RECORD(Three, \
        FIELD(a, i32) \
        VECTOR(b, i16) \
    )\
    RECORD(Four, EMPTY())\
    RECORD(Five,\
        ANY(a)\
        ANY(b)\
    )\
    RECORD(Six,\
        VECTOR_ANY(a)\
    )\
    RECORD(Seven, \
        FIELD(a, i32) \
        VECTOR_ANY(b) \
    )\
    RECORD(Eight, \
        ANY_OF(a, (One)(Three) ) \
    )\
    RECORD(Nine, \
        VECTOR_ANY_OF(a, (One)(Three)) \
    )\
    RECORD(Ten, \
        EMPTY()\
    )\
    RECORD(Eleven,\
        STRING(a)\
    )\
    RECORD(Rec,\
        VECTOR(ids, i64)\
        VECTOR_ANY(strings)\
    )

THIR_GENERATE_HEADER(MAIN_DEFINITION)

#include <thir/undef.h>

#endif
