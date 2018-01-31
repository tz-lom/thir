#include <boost/preprocessor/comparison/greater.hpp>
#include <boost/preprocessor/seq.hpp>
#include <boost/preprocessor/list.hpp>
#include <boost/preprocessor/punctuation/remove_parens.hpp>

#define RECORD(name, Fields) ((name)()(Fields))

#define FIELD(name, type) ((PROTO_NAMESPACE::Plain<type>)(name))
#define VECTOR(name, type) ((PROTO_NAMESPACE::Vector<type>)(name))
#define ANY(name) ((PROTO_NAMESPACE::Any)(name))
#define EMPTY()    ((PROTO_NAMESPACE::Void)(__void))
#define STRING(name) VECTOR(name, char)
#define VECTOR_ANY(name) ((PROTO_NAMESPACE::VectorOfAny)(name))

#define GENERATE_ID_VALIDATOR(s, state, x) \
    (PROTO_NAMESPACE::IDValidator< x::ID, BOOST_PP_REMOVE_PARENS(state) >)

#define GENERATE_ID_VALIDATOR_SEQ(seq) \
    BOOST_PP_REMOVE_PARENS(BOOST_PP_SEQ_FOLD_LEFT(GENERATE_ID_VALIDATOR, PROTO_NAMESPACE::__Last, seq))

#define ANY_OF(name, types) (( (PROTO_NAMESPACE::AnyOf< GENERATE_ID_VALIDATOR_SEQ(types) >) )(name))
//#define ANY_OF(name, type) (((PROTO_NAMESPACE::Any)(name))



#define DECLARE_FIELD(r, data, descr) \
    struct BOOST_PP_SEQ_ELEM(1, descr): Field< BOOST_PP_REMOVE_PARENS( BOOST_PP_SEQ_ELEM(0, descr) ), BOOST_PP_SEQ_ELEM(2,descr) > {};

#define GENERATE_PARENT(s, state, x) \
    BOOST_PP_SEQ_PUSH_FRONT(state, \
      BOOST_PP_SEQ_PUSH_BACK(x, \
        BOOST_PP_SEQ_ELEM(1, BOOST_PP_SEQ_HEAD(state) ) \
    ) )

#define GENERATE_STRUCTS(Fields)\
    BOOST_PP_SEQ_TAIL(BOOST_PP_SEQ_REVERSE(\
            BOOST_PP_SEQ_FOLD_LEFT(GENERATE_PARENT, \
                           (()(PROTO_NAMESPACE::First)) \
                           , Fields)\
    ))


#define GENERATE_HEADER_SIZE(r, data, x) \
    + BOOST_PP_SEQ_ELEM(1,x)::headerSize

#define GENERATE_STATIC_SIZE(r, data, x) \
    + BOOST_PP_SEQ_ELEM(1,x)::staticSize



#define GENERATE_CONSTRUCTOR_SIGNATURE_Field(name, type) type name
#define GENERATE_CONSTRUCTOR_SIGNATURE_Vector(name, type) BOOST_PP_CAT(___Vector_type_,name) name
#define GENERATE_CONSTRUCTOR_SIGNATURE_Any(name, type) SerializedData *name
#define GENERATE_CONSTRUCTOR_SIGNATURE_Void(name, type)
#define GENERATE_CONSTRUCTOR_SIGNATURE_String(name, type) BOOST_PP_CAT(___String_type_,name) name
#define GENERATE_CONSTRUCTOR_SIGNATURE_AnyVector(name, type) vector<SerializedData*> name

#define GENERATE_CONSTRUCTOR_SIGNATURE_FI(x) \
    BOOST_PP_CAT(GENERATE_CONSTRUCTOR_SIGNATURE_, BOOST_PP_SEQ_ELEM(0,x)) (BOOST_PP_SEQ_ELEM(1,x), BOOST_PP_SEQ_ELEM(2,x))

#define GENERATE_CONSTRUCTOR_SIGNATURE_F(s, state, x)\
    , GENERATE_CONSTRUCTOR_SIGNATURE_FI(x)

#define GENERATE_CONSTRUCTOR_SIGNATURE(x) \
    GENERATE_CONSTRUCTOR_SIGNATURE_FI(BOOST_PP_SEQ_HEAD(x)) \
    BOOST_PP_SEQ_FOR_EACH(GENERATE_CONSTRUCTOR_SIGNATURE_F, _, BOOST_PP_SEQ_TAIL(x))


#define GENERATE_CONSTRUCTOR_TEMPLATE_SIGNATURE_Field(name)
#define GENERATE_CONSTRUCTOR_TEMPLATE_SIGNATURE_Any(name)
#define GENERATE_CONSTRUCTOR_TEMPLATE_SIGNATURE_Void(name)
#define GENERATE_CONSTRUCTOR_TEMPLATE_SIGNATURE_Vector(name) (BOOST_PP_CAT(typename ___Vector_type_,name))
#define GENERATE_CONSTRUCTOR_TEMPLATE_SIGNATURE_String(name) (BOOST_PP_CAT(typename ___String_type_,name))
#define GENERATE_CONSTRUCTOR_TEMPLATE_SIGNATURE_AnyVector(name)

#define GENERATE_CONSTRUCTOR_TEMPLATE_SIGNATURE_F(r, data, x) \
    BOOST_PP_CAT(GENERATE_CONSTRUCTOR_TEMPLATE_SIGNATURE_, BOOST_PP_SEQ_ELEM(0, x))(BOOST_PP_SEQ_ELEM(1,x))


#define FORMAT_AS_TEMPLATE_EL(r, data, x) \
    BOOST_PP_COMMA() x

#define FORMAT_AS_TEMPLATE(list) \
    BOOST_PP_IF(BOOST_PP_SEQ_SIZE(list), template< , BOOST_PP_EMPTY())\
    BOOST_PP_IF(BOOST_PP_SEQ_SIZE(list), BOOST_PP_SEQ_ENUM, BOOST_PP_EMPTY) (list) \
    BOOST_PP_IF(BOOST_PP_SEQ_SIZE(list), > , BOOST_PP_EMPTY())

#define GENERATE_CONSTRUCTOR_TEMPLATE_SIGNATURE(Fields) \
    FORMAT_AS_TEMPLATE( BOOST_PP_SEQ_FOR_EACH(GENERATE_CONSTRUCTOR_TEMPLATE_SIGNATURE_F,_, Fields) )

#define GENERATE_CONSTRUCTOR_TEMPLATE_VARIABLES_Field(name)
#define GENERATE_CONSTRUCTOR_TEMPLATE_VARIABLES_Any(name) assert(name!=0);
#define GENERATE_CONSTRUCTOR_TEMPLATE_VARIABLES_Void(name)
#define GENERATE_CONSTRUCTOR_TEMPLATE_VARIABLES_Vector(name) vectorConvert<BOOST_PP_CAT(___Vector_type_,name) > BOOST_PP_CAT(___Vector_,name)(name);
#define GENERATE_CONSTRUCTOR_TEMPLATE_VARIABLES_String(name) stringConvert<BOOST_PP_CAT(___Vector_type_,name) > BOOST_PP_CAT(___Vector_,name)(name);
#define GENERATE_CONSTRUCTOR_TEMPLATE_VARIABLES_AnyVector(name)


#define GENERATE_CONSTRUCTOR_TEMPLATE_VARIABLES_F(r, data, x) \
    BOOST_PP_CAT(GENERATE_CONSTRUCTOR_TEMPLATE_VARIABLES_, BOOST_PP_SEQ_ELEM(0, x))(BOOST_PP_SEQ_ELEM(1,x))

#define GENERATE_CONSTRUCTOR_TEMPLATE_VARIABLES(Fields) \
    BOOST_PP_SEQ_FOR_EACH(GENERATE_CONSTRUCTOR_TEMPLATE_VARIABLES_F ,_, Fields)


#define GENERATE_CONSTRUCTOR_SIZE_Field(name) sizeof(name)
#define GENERATE_CONSTRUCTOR_SIZE_Vector(name) sizeof(hel)+sizeof(*BOOST_PP_CAT(___Vector_,name).begin())*(BOOST_PP_CAT(___Vector_,name).end()-BOOST_PP_CAT(___Vector_,name).begin())
#define GENERATE_CONSTRUCTOR_SIZE_Any(name) sizeof(hel)+name->size()
#define GENERATE_CONSTRUCTOR_SIZE_Void(name) 0
#define GENERATE_CONSTRUCTOR_SIZE_String(name) sizeof(hel)+sizeof(char)*(BOOST_PP_CAT(___String_,name).end()-BOOST_PP_CAT(___String_,name).begin())
#define GENERATE_CONSTRUCTOR_SIZE_AnyVector(name) sizeof(hel)+

#define GENERATE_CONSTRUCTOR_SIZE(g, data, x)\
    + BOOST_PP_CAT(GENERATE_CONSTRUCTOR_SIZE_, BOOST_PP_SEQ_ELEM(0,x)) (BOOST_PP_SEQ_ELEM(1,x))

#define GENERATE_CONSTRUCTOR_SETTER_Field(name, type)\
    *(reinterpret_cast<type*>(___offset)) = byte_order_to_le(name);\
    ___offset += sizeof(name);

#define GENERATE_CONSTRUCTOR_SETTER_Vector(name, type)\
    for(typename vectorConvert< BOOST_PP_CAT(___Vector_type_,name) >::IteratorType ___i=BOOST_PP_CAT(___Vector_,name).begin(); ___i<BOOST_PP_CAT(___Vector_,name).end(); ++___i, ___offset+=sizeof(*BOOST_PP_CAT(___Vector_,name).begin())){\
        *(reinterpret_cast<type*>(___offset)) = byte_order_to_le(*___i);\
    }

#define GENERATE_CONSTRUCTOR_SETTER_Any(name, type)\
    std::memcpy(___offset, name->data(), name->size()); \
    ___offset += name->size();

#define GENERATE_CONSTRUCTOR_SETTER_String(name, type)\
    std::copy(BOOST_PP_CAT(___String_,name).begin(), BOOST_PP_CAT(___String_,name).end(), *(reinterpret_cast<type*>(___offset))); \
    ___offset += BOOST_PP_CAT(___String_,name).end() - BOOST_PP_CAT(___String_,name).begin();\

#define GENERATE_CONSTRUCTOR_SETTER_Void(name, type)

#define GENERATE_CONSTRUCTOR_SETTER(g, data, x)\
    BOOST_PP_CAT(GENERATE_CONSTRUCTOR_SETTER_, BOOST_PP_SEQ_ELEM(0,x)) (BOOST_PP_SEQ_ELEM(1,x), BOOST_PP_SEQ_ELEM(2,x))

#define GENERATE_VALUE_SETTER_CHAIN(r, data, Field) \
    PROTO_NAMESPACE::ValueSetter < data::BOOST_PP_SEQ_ELEM(1,Field),

#define GENERATE_VALUE_SETTER_CHAIN_VALCON(r, data, x)\
    >

#define GENERATE_VALUE_SETTER_CHAIN_ROOT(r, data, x)\
    >

/*

BOOST_PP_SEQ_FOR_EACH(GENERATE_VALUE_SETTER_CHAIN,Name, Fields)\
__Last\
BOOST_PP_SEQ_FOR_EACH(GENERATE_VALUE_SETTER_CHAIN_ROOT,_, Fields)\

*/

#define GENERATE_VALUE_SETTER_CONSTRUCTOR(Name,Fields) \
    Name::constructor<PROTO_NAMESPACE::ValueSetter<PROTO_NAMESPACE::__Last, PROTO_NAMESPACE::__Last> >::type


#define GENERATE_RECORD(Name, Id, Fields) \
struct Name: PROTO_NAMESPACE::Record<Id, Name> { \
    BOOST_PP_SEQ_FOR_EACH(DECLARE_FIELD,_,GENERATE_STRUCTS(Fields))\
    \
    enum {\
        headerSize = 0 BOOST_PP_SEQ_FOR_EACH(GENERATE_HEADER_SIZE,_,Fields), \
        staticSize = 0 BOOST_PP_SEQ_FOR_EACH(GENERATE_STATIC_SIZE,_,Fields) \
    };\
    \
    typedef \
    BOOST_PP_SEQ_FOR_EACH(GENERATE_VALUE_SETTER_CHAIN,Name, Fields)\
    PROTO_NAMESPACE::ValueSetter<PROTO_NAMESPACE::__Last, PROTO_NAMESPACE::__Last> \
    BOOST_PP_SEQ_FOR_EACH(GENERATE_VALUE_SETTER_CHAIN_VALCON,_, Fields)\
    recursive;\
    \
    static recursive create();\
};\

#define GENERATE_CONSTRUCTOR(Name, Fields)\
Name::recursive Name::create()\
{\
    PROTO_NAMESPACE::SerializedData* sd = new PROTO_NAMESPACE::SerializedData(sizeof(PROTO_NAMESPACE::SerializedData::rid) + \
                                            headerSize * \
                                            sizeof(PROTO_NAMESPACE::SerializedData::hel) + \
                                            staticSize); \
    PROTO_NAMESPACE::RecordConstructor *rc = new PROTO_NAMESPACE::RecordConstructor(sd); \
    rc->beginNested(ID, staticSize, headerSize, {0,0}); \
    return recursive(rc); \
}\

#define GENERATE_CONSTRUCTORS(r, data, i , Record) \
    GENERATE_CONSTRUCTOR(BOOST_PP_SEQ_ELEM(0, Record), BOOST_PP_SEQ_ELEM(2, Record))

#define INJECT_RECORD_ID_1st(Record) \
    BOOST_PP_IF( \
        BOOST_PP_SEQ_SIZE(BOOST_PP_SEQ_ELEM(1, Record)),\
        (Record), \
        (BOOST_PP_SEQ_REPLACE(Record, 1, 1)) \
    )

#define GENERATE_RECORD_ID(s, Prev, Record) \
    BOOST_PP_IF( \
        BOOST_PP_SEQ_SIZE(BOOST_PP_SEQ_ELEM(1, Record)),\
        BOOST_PP_SEQ_PUSH_FRONT(Prev, Record),\
        BOOST_PP_SEQ_PUSH_FRONT(Prev, BOOST_PP_SEQ_REPLACE(Record, 1, BOOST_PP_SEQ_ELEM(1, BOOST_PP_SEQ_HEAD(Prev))+1) ) \
    )

#define GENERATE_RECORD_ID_n(r, data, i, x)\
    (BOOST_PP_SEQ_REPLACE(x, 1, i+1))

#define INJECT_RECORD_IDS(Records) \
    BOOST_PP_SEQ_FOR_EACH_I(GENERATE_RECORD_ID_n, _, Records)


#define GENERATE_RECORD_CALL(r,data,i,record) \
    GENERATE_RECORD(BOOST_PP_SEQ_ELEM(0,record), BOOST_PP_SEQ_ELEM(1,record), BOOST_PP_SEQ_ELEM(2,record))

#define GENERATE_CONSTRUCTOR_HEADER(Name, Fields) \
    GENERATE_CONSTRUCTOR_TEMPLATE_SIGNATURE(Fields) \
    static SerializedData* BOOST_PP_CAT(create_, Name)(GENERATE_CONSTRUCTOR_SIGNATURE(Fields));

#define GENERATE_CONSTRUCTOR_HEADERS(r, data, i, record) \
    GENERATE_CONSTRUCTOR_HEADER(BOOST_PP_SEQ_ELEM(0, record), BOOST_PP_SEQ_ELEM(2, record))


#define GENERATE_ENUM_CONTENTS(r, data, i, record)\
    BOOST_PP_SEQ_ELEM(0,record) = BOOST_PP_SEQ_ELEM(1, record) BOOST_PP_COMMA()

#define GENERATE_PREFIX_I(Records) \
    BOOST_PP_SEQ_FOR_EACH_I(GENERATE_RECORD_CALL,_,Records) \

#define GENERATE_HEADER(Records) \
    GENERATE_PREFIX_I(INJECT_RECORD_IDS(Records))

#define GENERATE_CLASS_H(Records) GENERATE_CLASS_H_I(INJECT_RECORD_IDS(Records))
#define GENERATE_IMPLEMENTATION(Records) GENERATE_CLASS_CPP_I(INJECT_RECORD_IDS(Records))

#define GENERATE_CLASS_FRIEND(r, data, i, record) \
    friend struct BOOST_PP_SEQ_ELEM(0,record);\

//  constructors within class if you want
//     BOOST_PP_SEQ_FOR_EACH_I(GENERATE_CONSTRUCTOR_HEADERS,_,Records)
//BOOST_PP_SEQ_FOR_EACH_I(GENERATE_ENUM_CONTENTS,_,Records)

#define GENERATE_CLASS_H_I(Records) \
    enum { \
    __LastType = BOOST_PP_SEQ_ELEM(0, BOOST_PP_SEQ_HEAD(BOOST_PP_SEQ_REVERSE(Records)))::ID\
    };\
    BOOST_PP_SEQ_FOR_EACH_I(GENERATE_CLASS_FRIEND,_,Records)\


#define GENERATE_CLASS_TEMPLATES_I(Records) \
    BOOST_PP_SEQ_FOR_EACH_I(GENERATE_CONSTRUCTORS,_,Records)

#define GENERATE_CLASS_TEMPLATES(Records)\
    GENERATE_CLASS_TEMPLATES_I(FILTER_NON_TEMPLATE_RECORDS(INJECT_RECORD_IDS(Records)))

#define GENERATE_STATIC_HEADER_SIZE(r, data, i, record)\
    BOOST_PP_COMMA() BOOST_PP_SEQ_ELEM(0, record)::headerSize

#define GENERATE_STATIC_STATIC_SIZE(r, data, i, record)\
    BOOST_PP_COMMA() BOOST_PP_SEQ_ELEM(0, record)::staticSize

#define GENERATE_STATIC_LAST_ID(s, state, x) \
    BOOST_PP_SEQ_ELEM(0, x)

#define GENERATE_CLASS_CPP_I(Records) \
    BOOST_PP_SEQ_FOR_EACH_I(GENERATE_CONSTRUCTORS,_,Records)\
    const size_t PROTO_NAMESPACE::SerializedData::headerSizes[] = {0 BOOST_PP_SEQ_FOR_EACH_I(GENERATE_STATIC_HEADER_SIZE,_,Records) };\
    const size_t PROTO_NAMESPACE::SerializedData::staticSizes[] = {0 BOOST_PP_SEQ_FOR_EACH_I(GENERATE_STATIC_STATIC_SIZE,_,Records) };\
    const size_t PROTO_NAMESPACE::SerializedData::__LastType = BOOST_PP_SEQ_FOLD_LEFT( GENERATE_STATIC_LAST_ID , 0, Records)::ID ;

#define FILTER_TEMPLATE_RECORDS_CALL(r,data,x) \
    data BOOST_PP_IF(\
        BOOST_PP_SEQ_SIZE(BOOST_PP_SEQ_FOR_EACH(GENERATE_CONSTRUCTOR_TEMPLATE_SIGNATURE_F,_, BOOST_PP_SEQ_ELEM(2,x))), \
        BOOST_PP_EMPTY(), \
        (x) \
    )

#define FILTER_TEMPLATE_RECORDS(Records) \
    BOOST_PP_SEQ_FOLD_LEFT(FILTER_TEMPLATE_RECORDS_CALL,,Records)

#define WRAPPER(x) x

#define FILTER_NON_TEMPLATE_RECORDS_CALL(r,data,x) \
    data BOOST_PP_IF(\
        BOOST_PP_SEQ_SIZE(BOOST_PP_SEQ_FOR_EACH(GENERATE_CONSTRUCTOR_TEMPLATE_SIGNATURE_F,_, BOOST_PP_SEQ_ELEM(2,x))), \
        (x), \
        BOOST_PP_EMPTY() \
    )

#define FILTER_NON_TEMPLATE_RECORDS(Records) \
    BOOST_PP_SEQ_FOLD_LEFT(FILTER_NON_TEMPLATE_RECORDS_CALL,,Records)
