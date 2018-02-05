# thir

s **T** ructurized  
s **H** ema-full  
b **I** nary  
p **R** otocol  

![Travis-CI](https://travis-ci.org/tz-lom/thir.svg?branch=master)

# What is it
It's a C++ library for definition binary serialization schema which creates fast compact and predictable binary fragments, which can be easily readed and created using C++ classes.
The library supports C++98 and newer and have only Boost headers in dependencies. The library itself have no linking objects and can be used in header or in header and .cpp file.
The library depends from the following Boost >=1.58 components:
* boost/preprocessor
* boost/endian
* boost/shared_ptr [ if compiled without C++11 support]
All these libraries are header-only.


# Storage format

![Byte decomposition diagram](http://www.plantuml.com/plantuml/png/bPGn2uCm48Nt_8gRFJAqRaB1GOJE7Kk5gmeALa6pjEJ7Dz4YHfDeR_buA8-NTz5u4DIBeXP4Z85za9k37iNHvI8XURVqgdCOwayvA7qJ99GiID3YwIIP8mPkNDtAwYBXckZtghA19TFJX50ZFTyV6g629ykg0VJ0tOkUp4u3cSz0scb0idbLk368x3GGCQbhgbkX77zE5-uO_3U1TEpGDFYZ0_0ds6POTs0tqBT3Tp3U4BE2WFi6znE0zmYmty4n0tGiwx21_ZJWsNKDvXNrSnFB2JmIBGaOOt7P5kEVw0i0)


License
----
MIT
