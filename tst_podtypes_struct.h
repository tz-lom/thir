#define POD_DEFINITION \
    RECORD(PODcontainer, \
        FIELD(I8, i8) \
        FIELD(U64, u64) \
    )\
    RECORD(OneBool, \
        FIELD(B, bool) \
    )\
    RECORD(Empty, EMPTY())\
    RECORD(PodVector,\
        VECTOR(vals, i32)\
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

#include "generate_namespace_include.h"
GENERATE_PREFIX(POD_DEFINITION)
#include "generate_class_prefix.h"
GENERATE_CLASS_H(POD_DEFINITION)
#include "generate_class_postfix.h"

#include "generate_class_implementation.h"
GENERATE_CLASS_CPP(POD_DEFINITION)


#include "generate_undef.h"
