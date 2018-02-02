#ifndef TESTS_MAIN_STRUCTURES
#define TESTS_MAIN_STRUCTURES


#include "protocol/classes.h"
#include "protocol/fields/all.h"

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

#define POD_DEFINITION \
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
    RECORD(String,\
        STRING(str)\
    )\
    RECORD(Rec,\
        VECTOR(ids, i64)\
        VECTOR_ANY(strings)\
    )


#include "generate.h"

GENERATE_HEADER(POD_DEFINITION)

#include "generate_undef.h"

#endif
