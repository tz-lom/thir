CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)


PROJECT(simpleProtocol
        LANGUAGES CXX)

find_package(Threads REQUIRED)

if ($ENV{GOOGLETEST_DIR})
    SET(GOOGLETEST_DIR $ENV{GOOGLETEST_DIR})
else ()
    message(WARNING "Using googletest src dir specified at Qt Creator wizard")
    SET(GOOGLETEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/googletest)
endif ()
if (EXISTS ${GOOGLETEST_DIR})
    SET(GTestSrc ${GOOGLETEST_DIR}/googletest)
    SET(GMockSrc ${GOOGLETEST_DIR}/googlemock)
else ()
    message( FATAL_ERROR "No googletest src dir found - set GOOGLETEST_DIR to enable!")
endif ()

set(ProtocolFiles
    protocol/generate.h
    protocol/generate_undef.h
    protocol/classes.h
    protocol/classes.imp.h
    protocol/fields/all.h
    protocol/fields/base.h
    protocol/fields/Any.h
    protocol/fields/AnyOf.h
    protocol/fields/Plain.h
    protocol/fields/Vector.h
    protocol/fields/VectorOfAny.h
    protocol/fields/VectorOfAnyOf.h
    protocol/fields/Last.h
    protocol/fields/Void.h
    )

set(TestFiles
    main.cpp
    tests.h
    structures.h
    structures.cpp
    test_binary_little_endian.h
    test_binary_big_endian.h
    )

include_directories(${GTestSrc} ${GTestSrc}/include ${GMockSrc} ${GMockSrc}/include ${CMAKE_CURRENT_SOURCE_DIR}/protocol)
add_executable(tests_little
    ${TestFiles}
    ${ProtocolFiles}
    ${GTestSrc}/src/gtest-all.cc
    ${GMockSrc}/src/gmock-all.cc
    )
target_compile_definitions(tests_little PRIVATE PROTO_SEND_ENDIAN=little)
add_test(${PROJECT_NAME} COMMAND tests_little)
target_link_libraries(tests_little PRIVATE Threads::Threads)

add_executable(tests_big
    ${TestFiles}
    ${ProtocolFiles}
    ${GTestSrc}/src/gtest-all.cc
    ${GMockSrc}/src/gmock-all.cc
    )
target_compile_definitions(tests_big PRIVATE PROTO_SEND_ENDIAN=big)
add_test(${PROJECT_NAME} COMMAND tests_big)
target_link_libraries(tests_big PRIVATE Threads::Threads)

#add_executable(speedTest speedtest.cpp)

set(CMAKE_CXX_STANDARD 98)

#add_executable(model model.cpp
#    ${ProtocolFiles}
#    )

