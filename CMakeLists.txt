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


include_directories(${GTestSrc} ${GTestSrc}/include ${GMockSrc} ${GMockSrc}/include ${CMAKE_CURRENT_SOURCE_DIR}/protocol)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/protocol ProtocolDefinitions)
add_executable(${PROJECT_NAME} main.cpp tst_podtypes.h
    tst_podtypes_struct.h
    tst_podtypes_struct.expanded.h
    ${ProtocolDefinitions}
               ${GTestSrc}/src/gtest-all.cc
               ${GMockSrc}/src/gmock-all.cc)
add_test(${PROJECT_NAME} COMMAND ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

add_executable(speedTest speedtest.cpp)

set(CMAKE_CXX_STANDARD 98)

add_executable(model model.cpp classes.h classes.imp.h)

