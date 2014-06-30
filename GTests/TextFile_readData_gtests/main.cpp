
#include "gtest/gtest.h"
#include "freeFunctions.h"

TEST( readData_001, EmptyArgumentTest )
{
    // Input data
    QString fileName = "";
    QString content;

    // Actual result
    ASSERT_THROW( {
                      readData( fileName, content );
                  }, EmptyArgument );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
