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
    RECORD(String,\
        STRING(str)\
    )\
    RECORD(Rec,\
        VECTOR(ids, i64)\
        VECTOR_ANY(strings)\
    )


#include "generate.h"

GENERATE_HEADER(POD_DEFINITION)
GENERATE_IMPLEMENTATION(POD_DEFINITION)



#include "generate_undef.h"
