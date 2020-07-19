#undef RECORD
#undef FIELD
#undef VECTOR
#undef ANY
#undef EMPTY
#undef STRING
#undef VECTOR_ANY
#undef ANY_OF
#undef VECTOR_ANY_OF

#ifdef THIR_AUTO_DYNAMIC_SIZE_TYPE
#  undef THIR_DYNAMIC_SIZE_TYPE
#endif
#ifdef THIR_AUTO_ID_TYPE
#  undef THIR_ID_TYPE
#endif
#ifdef THIR_AUTO_NAMESPACE
#  undef THIR_NAMESPACE
#endif
#ifdef THIR_AUTO_SEND_ENDIAN
#  undef THIR_SEND_ENDIAN
#endif

#undef THIR_GENERATE_HEADER
#undef THIR_GENERATE_IMPLEMENTATION

#undef THIR_NS
#undef THIR_NAMESPACE_OPEN
#undef THIR_NAMESPACE_CLOSE
#undef THIR_NAMESPACE_OPEN_CODE
#undef THIR_NAMESPACE_CLOSE_CODE
#undef THIR_NAMESPACE_DECLARE

#undef THIR_PRIV_GEN_ID_VALIDATOR
#undef THIR_PRIV_GEN_ID_VALIDATOR_SEQ
#undef THIR_PRIV_GEN_DECLARE_FIELD
#undef THIR_PRIV_GEN_PARENT
#undef THIR_PRIV_GEN_HEADER_SIZE
#undef THIR_PRIV_GEN_STATIC_SIZE
#undef THIR_PRIV_GEN_VALUE_SETTER_CHAIN
#undef THIR_PRIV_GEN_VALUE_SETTER_CHAIN_VALCON
#undef THIR_PRIV_GEN_RECORD
#undef THIR_PRIV_GEN_STRUCTS
#undef THIR_PRIV_GEN_CONSTRUCTOR
#undef THIR_PRIV_GEN_CONSTRUCTORS
#undef THIR_PRIV_GEN_RECORD_ID_n
#undef THIR_PRIV_GEN_INJECT_RECORD_IDS
#undef THIR_PRIV_GEN_RECORD_CALL
#undef THIR_PRIV_GEN_STATIC_HEADER_SIZE
#undef THIR_PRIV_GEN_STATIC_STATIC_SIZE
#undef THIR_PRIV_GEN_STATIC_LAST_ID
#undef THIR_PRIV_GEN_CLASS_CPP_I
#undef THIR_PRIV_GEN_CONSTRUCTORS

#ifdef THIR_PRIV_ENDCONV_ENABLE
#  undef THIR_PRIV_ENDCONV_ENABLE
#endif

#undef THIR_PRIV_END_little
#undef THIR_PRIV_END_big
#undef THIR_PRIV_ENDIAN_TEST
#undef THIR_EXTENSION_IDENT
#undef THIR_EXTENSION_INCLUDE
#undef THIR_IS_CPP11
#undef THIR_NULLPTR
