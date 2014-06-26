
#include <string>
#include <vector>

#include <QString>

#include "gtest/gtest.h"
#include "freeFunctions.h"
#include "EmptyArgument.h"
#include "OutOfRange.h"
#include "NotNumber.h"

TEST( parseToIntArray001, emptyArgumentTest )
{
    QString content = "";
    std::vector<int> arr;

    ASSERT_THROW( {
                      parseToIntArray( content, arr );
                  }, EmptyArgument );
}

TEST( parseToIntArray002, outOfRangeTest )
{
    QString content = "56 -100 78";
    std::vector<int> arr;

    ASSERT_NO_THROW( {
                         parseToIntArray( content, arr );
                     } );
}

TEST( parseToIntArray003, outOfRangeTest )
{
    QString content = "56 -101 78";
    std::vector<int> arr;

    ASSERT_THROW( {
                      parseToIntArray( content, arr );
                  }, OutOfRange );
}

TEST( parseToIntArray004, outOfRangeTest )
{
    QString content = "56 100 78";
    std::vector<int> arr;

    ASSERT_NO_THROW( {
                         parseToIntArray( content, arr );
                     } );
}

TEST( parseToIntArray005, outOfRangeTest )
{
    QString content = "56 101 78";
    std::vector<int> arr;

    ASSERT_THROW( {
                      parseToIntArray( content, arr );
                  }, OutOfRange );
}

TEST( parseToIntArray006, notNumberTest )
{
    QString content = "56 10w 78";
    std::vector<int> arr;

    ASSERT_THROW( {
                      parseToIntArray( content, arr );
                  }, NotNumber );
}

TEST( parseToIntArray007, normalTest )
{
    QString content = "56 100 78";

    // Actual
    std::vector<int> actualArray;
    ASSERT_NO_THROW( {
                         parseToIntArray( content, actualArray );
                     } );

    // Expected
    std::vector<int> expectedArray;
    expectedArray.push_back( 56 );
    expectedArray.push_back( 100 );
    expectedArray.push_back( 78 );

    // Check sizes
    std::size_t expectedSize = expectedArray.size( );
    std::size_t actualSize = actualArray.size( );
    ASSERT_EQ( expectedSize, actualSize );

    // Check the actual array
    for( std::size_t i = 0; i < expectedSize; i++ ) {
        ASSERT_EQ( expectedArray[i], actualArray[i] );
    }
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
