#include <boost/preprocessor/comparison/greater.hpp>
#include <boost/preprocessor/seq.hpp>
#include <boost/preprocessor/list.hpp>
#include <boost/preprocessor/punctuation/remove_parens.hpp>
#include <boost/preprocessor/cat.hpp>

// Thir settings
#ifndef THIR_DYNAMIC_SIZE_TYPE
#  define THIR_DYNAMIC_SIZE_TYPE uint32_t
#  define THIR_AUTO_DYNAMIC_SIZE_TYPE
#endif
#ifndef THIR_ID_TYPE
#  define THIR_ID_TYPE uint16_t
#  define THIR_AUTO_ID_TYPE
#endif
#ifndef THIR_NAMESPACE
#  define THIR_NAMESPACE (Thir)
#  define THIR_AUTO_NAMESPACE
#endif
#ifndef THIR_SEND_ENDIAN
#  define THIR_SEND_ENDIAN little
#  define THIR_AUTO_SEND_ENDIAN
#endif



#define RECORD(name, Fields) ((name)()(Fields))

#define FIELD(name, type) (( (THIR_NS::Plain<type>) )(name))
#define VECTOR(name, type) (( (THIR_NS::Vector<type>) )(name))
#define ANY(name) (( (THIR_NS::Any) )(name))
#define EMPTY()    (( (THIR_NS::Void) )(__void))
#define STRING(name) VECTOR(name, char)
#define VECTOR_ANY(name) (( (THIR_NS::VectorOfAny) )(name))
#define ANY_OF(name, types) (( (THIR_NS::AnyOf< THIR_PRIV_GEN_ID_VALIDATOR_SEQ(types) >) )(name))
#define VECTOR_ANY_OF(name, types) (( (THIR_NS::VectorOfAnyOf< THIR_PRIV_GEN_ID_VALIDATOR_SEQ(types) >) )(name))



#define THIR_NAMESPACE_OPEN_CODE(s, data, x) namespace x {
#define THIR_NAMESPACE_OPEN BOOST_PP_SEQ_FOR_EACH(THIR_NAMESPACE_OPEN_CODE, , THIR_NAMESPACE)

#define THIR_NAMESPACE_CLOSE_CODE(s, state, x)  }
#define THIR_NAMESPACE_CLOSE BOOST_PP_SEQ_FOR_EACH(THIR_NAMESPACE_CLOSE_CODE, ,THIR_NAMESPACE)

#define THIR_NAMESPACE_DECLARE(r, state, x) BOOST_PP_CAT(state, ::x)
#define THIR_NS BOOST_PP_SEQ_FOLD_LEFT(THIR_NAMESPACE_DECLARE, ,THIR_NAMESPACE)

#define EXP_I(r, data, x) BOOST_PP_COMMA() x

#define THIR_PRIV_OPEN_PARENS(x)  BOOST_PP_SEQ_ELEM(0,x) BOOST_PP_LIST_FOR_EACH(EXP_I, _, BOOST_PP_SEQ_TO_LIST(BOOST_PP_SEQ_TAIL(x)))


#define THIR_PRIV_GEN_ID_VALIDATOR(s, data, x) THIR_NS::IDValidator< x::ID)(
#define THIR_PRIV_GEN_ID_VALIDATOR_CLOSE(s, state, x) > state

#define THIR_PRIV_GEN_ID_VALIDATOR_SEQ(seq) \
    BOOST_PP_SEQ_FOR_EACH(THIR_PRIV_GEN_ID_VALIDATOR,,seq) THIR_NS::__Last BOOST_PP_SEQ_FOLD_LEFT(THIR_PRIV_GEN_ID_VALIDATOR_CLOSE, , seq)



#define THIR_PRIV_GEN_DECLARE_FIELD(r, data, descr) \
    struct BOOST_PP_SEQ_ELEM(1, descr): Field< THIR_PRIV_OPEN_PARENS( BOOST_PP_SEQ_ELEM(0, descr) ), BOOST_PP_SEQ_ELEM(2,descr) > {};

#define THIR_PRIV_GEN_PARENT(s, state, x) \
    BOOST_PP_SEQ_PUSH_FRONT(state, \
      BOOST_PP_SEQ_PUSH_BACK(x, \
        BOOST_PP_SEQ_ELEM(1, BOOST_PP_SEQ_HEAD(state) ) \
    ) )

#define THIR_PRIV_GEN_STRUCTS(Fields)\
    BOOST_PP_SEQ_TAIL(BOOST_PP_SEQ_REVERSE(\
            BOOST_PP_SEQ_FOLD_LEFT(THIR_PRIV_GEN_PARENT, \
                           (()(THIR_NS::First)) \
                           , Fields)\
    ))


#define THIR_PRIV_GEN_HEADER_SIZE(r, data, x) \
    + BOOST_PP_SEQ_ELEM(1,x)::headerSize

#define THIR_PRIV_GEN_STATIC_SIZE(r, data, x) \
    + BOOST_PP_SEQ_ELEM(1,x)::staticSize


#define THIR_PRIV_GEN_VALUE_SETTER_CHAIN(r, data, Field) \
    THIR_NS::ValueSetter < data::BOOST_PP_SEQ_ELEM(1,Field),

#define THIR_PRIV_GEN_VALUE_SETTER_CHAIN_VALCON(r, data, x)\
    >


#define THIR_PRIV_GEN_RECORD(r, Name, Id, Fields) \
struct Name: THIR_NS::Record<Id, Name> { \
    BOOST_PP_SEQ_FOR_EACH(THIR_PRIV_GEN_DECLARE_FIELD,_,THIR_PRIV_GEN_STRUCTS(Fields))\
    \
    enum {\
        headerSize = 0 BOOST_PP_SEQ_FOR_EACH(THIR_PRIV_GEN_HEADER_SIZE,_,Fields), \
        staticSize = 0 BOOST_PP_SEQ_FOR_EACH(THIR_PRIV_GEN_STATIC_SIZE,_,Fields) \
    };\
    \
    typedef \
    BOOST_PP_SEQ_FOR_EACH(THIR_PRIV_GEN_VALUE_SETTER_CHAIN,Name, Fields) \
    THIR_NS::ValueSetter<THIR_NS::__Last, THIR_NS::__Last> \
    BOOST_PP_SEQ_FOR_EACH(THIR_PRIV_GEN_VALUE_SETTER_CHAIN_VALCON,_, Fields)\
    recursive;\
    \
    static recursive create();\
};\

#define THIR_PRIV_GEN_CONSTRUCTOR(Name, Fields)\
Name::recursive Name::create()\
{\
    THIR_NS::SerializedData* sd = new THIR_NS::SerializedData(sizeof(THIR_NS::SerializedData::rid) + \
                                            headerSize * \
                                            sizeof(THIR_NS::SerializedData::hel) + \
                                            staticSize); \
    THIR_NS::RecordConstructor *rc = new THIR_NS::RecordConstructor(sd); \
    rc->beginNested(ID, staticSize, headerSize, THIR_NS::RecordConstructor::Fuse(0,0)); \
    return recursive(THIR_NS::RC(rc)); \
}\

#define THIR_PRIV_GEN_CONSTRUCTORS(r, data, i , Record) \
    THIR_PRIV_GEN_CONSTRUCTOR(BOOST_PP_SEQ_ELEM(0, Record), BOOST_PP_SEQ_ELEM(2, Record))



#define THIR_PRIV_GEN_RECORD_ID_n(r, data, i, x)\
    (BOOST_PP_SEQ_REPLACE(x, 1, i+1))

#define THIR_PRIV_GEN_INJECT_RECORD_IDS(Records) \
    BOOST_PP_SEQ_FOR_EACH_I(THIR_PRIV_GEN_RECORD_ID_n, _, Records)


#define THIR_PRIV_GEN_RECORD_CALL(r,data,i,record) \
    THIR_PRIV_GEN_RECORD(r, BOOST_PP_SEQ_ELEM(0,record), BOOST_PP_SEQ_ELEM(1,record), BOOST_PP_SEQ_ELEM(2,record))


#define THIR_PRIV_GEN_PREFIX_I(Records) \
    BOOST_PP_SEQ_FOR_EACH_I(THIR_PRIV_GEN_RECORD_CALL,_,Records) \

#define THIR_GENERATE_HEADER(Records) \
    THIR_PRIV_GEN_PREFIX_I(THIR_PRIV_GEN_INJECT_RECORD_IDS(Records))

#define THIR_GENERATE_IMPLEMENTATION(Records) THIR_PRIV_GEN_CLASS_CPP_I(THIR_PRIV_GEN_INJECT_RECORD_IDS(Records))

#define THIR_PRIV_GEN_STATIC_HEADER_SIZE(r, data, i, record)\
    BOOST_PP_COMMA() BOOST_PP_SEQ_ELEM(0, record)::headerSize

#define THIR_PRIV_GEN_STATIC_STATIC_SIZE(r, data, i, record)\
    BOOST_PP_COMMA() BOOST_PP_SEQ_ELEM(0, record)::staticSize

#define THIR_PRIV_GEN_STATIC_LAST_ID(s, state, x) \
    BOOST_PP_SEQ_ELEM(0, x)

#define THIR_PRIV_GEN_CLASS_CPP_I(Records) \
    BOOST_PP_SEQ_FOR_EACH_I(THIR_PRIV_GEN_CONSTRUCTORS,_,Records)\
    const size_t THIR_NS::SerializedData::headerSizes[] = {0 BOOST_PP_SEQ_FOR_EACH_I(THIR_PRIV_GEN_STATIC_HEADER_SIZE,_,Records) };\
    const size_t THIR_NS::SerializedData::staticSizes[] = {0 BOOST_PP_SEQ_FOR_EACH_I(THIR_PRIV_GEN_STATIC_STATIC_SIZE,_,Records) };\
    const size_t THIR_NS::SerializedData::__LastType = BOOST_PP_SEQ_FOLD_LEFT( THIR_PRIV_GEN_STATIC_LAST_ID , 0, Records)::ID ;

