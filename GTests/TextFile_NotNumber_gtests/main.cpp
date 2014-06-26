
#include <string>
#include "gtest/gtest.h"
#include "NotNumber.h"

TEST( test001, messageTest )
{
    std::string functionName = "parseToIntArray()";
    NotNumber error( functionName );

    std::string actual = error.message( );
    std::string expected = "Error: the argument in the "
            "function \"" + functionName + "\" must contain "
            "only numbers";
    ASSERT_EQ( expected, actual );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
