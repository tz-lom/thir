#include "tests.h"

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/stringize.hpp>


#include BOOST_PP_STRINGIZE(BOOST_PP_CAT(BOOST_PP_CAT(test_binary_, THIR_SEND_ENDIAN), _endian.h))

#include "test_parallel_definitions.h"

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
