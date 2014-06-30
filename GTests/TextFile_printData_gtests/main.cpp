
#include "gtest/gtest.h"
#include "freeFunctions.h"

TEST( printData_001, EmptyArgumentTest )
{
    // Input argument
    std::vector<Person> persons;

    // Actual result
    ASSERT_THROW( {
                      printData( persons );
                  }, EmptyArgument );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
