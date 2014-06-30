
#include "gtest/gtest.h"
#include "freeFunctions.h"

TEST( writeData_001, EmptyArgumentTest )
{
    // Input data
    QString fileName = "";
    QString content = "David White";

    // Actual result
    ASSERT_THROW( {
                      writeData( fileName, content );
                  }, EmptyArgument );
}

TEST( writeData_002, EmptyArgumentTest )
{
    // Input data
    QString fileName = "output.txt";
    QString content = "";

    // Actual result
    ASSERT_THROW( {
                      writeData( fileName, content );
                  }, EmptyArgument );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
