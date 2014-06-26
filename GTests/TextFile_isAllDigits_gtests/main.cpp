
#include <QString>
#include "gtest/gtest.h"
#include "freeFunctions.h"
#include "EmptyArgument.h"

TEST( isAllDigits001, emptyArgumentTest )
{
    QString content = "";

    ASSERT_THROW( {
                      isAllDigits( content );
                  }, EmptyArgument );
}

TEST( isAllDigits002, trueTest )
{
    QString content = "15 66 00";

    bool actual = false;
    ASSERT_NO_THROW( {
                         actual = isAllDigits( content );
                     } );
    bool expected = true;
    ASSERT_EQ( expected, actual );
}

TEST( isAllDigits003, trueTest )
{
    QString content = "1";

    bool actual = false;
    ASSERT_NO_THROW( {
                         actual = isAllDigits( content );
                     } );
    bool expected = true;
    ASSERT_EQ( expected, actual );
}

TEST( isAllDigits004, falseTest )
{
    QString content = "15 6w6 00";

    bool actual = true;
    ASSERT_NO_THROW( {
                         actual = isAllDigits( content );
                     } );
    bool expected = false;
    ASSERT_EQ( expected, actual );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
