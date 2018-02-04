CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

set(CMAKE_CXX_STANDARD 98)


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
    thir/generate.h
    thir/undef.h
    thir/classes.h
    thir/classes.imp.h
    thir/fields/all.h
    thir/fields/base.h
    thir/fields/Any.h
    thir/fields/AnyOf.h
    thir/fields/Plain.h
    thir/fields/Vector.h
    thir/fields/VectorOfAny.h
    thir/fields/VectorOfAnyOf.h
    thir/fields/Void.h
    )

set(TestFiles
    main.cpp
    tests.h
    structures.h
    structures.cpp
    test_binary_little_endian.h
    test_binary_big_endian.h
    test_parallel_definitions.h
    )

include_directories(${GTestSrc} ${GTestSrc}/include ${GMockSrc} ${GMockSrc}/include ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(tests_little
    ${TestFiles}
    ${ProtocolFiles}
    ${GTestSrc}/src/gtest-all.cc
    ${GMockSrc}/src/gmock-all.cc
    )
target_compile_definitions(tests_little PRIVATE THIR_SEND_ENDIAN=little)
add_test(${PROJECT_NAME} COMMAND tests_little)
target_link_libraries(tests_little PRIVATE Threads::Threads)

add_executable(tests_big
    ${TestFiles}
    ${ProtocolFiles}
    ${GTestSrc}/src/gtest-all.cc
    ${GMockSrc}/src/gmock-all.cc
    )
target_compile_definitions(tests_big PRIVATE THIR_SEND_ENDIAN=big)
add_test(${PROJECT_NAME} COMMAND tests_big)
target_link_libraries(tests_big PRIVATE Threads::Threads)

#add_executable(speedTest speedtest.cpp)

set(CMAKE_CXX_STANDARD 98)

#add_executable(model model.cpp
#    ${ProtocolFiles}
#    )

