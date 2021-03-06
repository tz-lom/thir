CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
set(CMAKE_CXX_STANDARD 98)
PROJECT(thir LANGUAGES CXX)

include(conanbuildinfo.cmake)
conan_basic_setup()

find_package(Threads REQUIRED)
find_package(gtest REQUIRED)
find_package(boost REQUIRED)

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
    thir/fields/String.h
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

set(TestExtensionQt
    test_ext_core.cpp
    test_ext_qt_.h
    structures.h
    structures.cpp
    thir/extensions/Qt/String_Field.h
    thir/extensions/Qt/String_Setter.h
    thir/extensions/Qt/String_Include.h
    )

include_directories(
    GTEST_INCLUDE_DIRS
	BOOST_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    boost/preprocessor/include
    boost/endian/include
    boost/config/include
    boost/predef/include
    boost/core/include
    boost/static_assert/include
    boost/type_traits/include
    )

add_executable(tests_little
    ${TestFiles}
    ${ProtocolFiles}
    )
target_compile_definitions(tests_little PRIVATE THIR_SEND_ENDIAN=little)
add_test(${PROJECT_NAME} COMMAND tests_little)
target_link_libraries(tests_little PRIVATE Threads::Threads ${GTEST_BOTH_LIBRARIES})

add_executable(tests_big
    ${TestFiles}
    ${ProtocolFiles}
    )
target_compile_definitions(tests_big PRIVATE THIR_SEND_ENDIAN=big)
add_test(${PROJECT_NAME} COMMAND tests_big)
target_link_libraries(tests_big PRIVATE Threads::Threads ${GTEST_BOTH_LIBRARIES})


add_executable(test_extension_qt
    ${TestExtensionQt}
    ${ProtocolFiles}
    )
find_package( Qt5Core )
set(CMAKE_CXX_STANDARD 14)
qt5_use_modules(test_extension_qt Core)

target_compile_definitions(test_extension_qt PRIVATE THIR_TEST_EXTENSION=qt)
add_test(${PROJECT_NAME} COMMAND test_extension_qt)
target_link_libraries(test_extension_qt Threads::Threads ${GTEST_BOTH_LIBRARIES})


#set(CMAKE_CXX_STANDARD 11)
#add_executable(speedTest speedtest.cpp structures.cpp)



