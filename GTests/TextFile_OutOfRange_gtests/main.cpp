
#include <string>

#include <boost/lexical_cast.hpp>

#include "gtest/gtest.h"
#include "OutOfRange.h"

TEST( test001, messageTest )
{
    std::string functionName = "readData()";
    int number = 50;
    int beginOfRange = -100;
    int endOfRange = 100;
    OutOfRange error( functionName, number, beginOfRange, endOfRange );

    std::string actual;
    ASSERT_NO_THROW( {
                        actual = error.message( );
                     } );
    std::string expected = "Error: the argument \"" +
            boost::lexical_cast<std::string>(number) +
            "\" doesn't hit into the range [" +
            boost::lexical_cast<std::string>(beginOfRange) + ", " +
            boost::lexical_cast<std::string>(endOfRange) + "]";
    ASSERT_EQ( expected, actual );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
