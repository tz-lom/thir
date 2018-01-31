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
    RECORD(AVector,\
        VECTOR_ANY(str)\
    )\
    RECORD(String,\
        STRING(str)\
    )\
    RECORD(Rec,\
        VECTOR(ids, i64)\
        VECTOR_ANY(strings)\
    )\
    RECORD(Str,\
        STRING(str)\
    )


#include "generate.h"

GENERATE_HEADER(POD_DEFINITION)
GENERATE_IMPLEMENTATION(POD_DEFINITION)


#include "generate_undef.h"
