
#include "gtest/gtest.h"
#include "freeFunctions.h"

TEST( parsePersonsToStrContent_001, EmptyArgumentTest )
{
    // Input data
    std::vector<Person> persons;

    // Actual result
    QString content;
    ASSERT_THROW( {
                      parsePersonsToStrContent( persons, content );
                  }, EmptyArgument );
}

TEST( parsePersonsToStrContent_002, twoPersonTest )
{
    // Input data
    Person david( "David", "White" );
    Person ivan( "Ivan", "Green" );
    std::vector<Person> persons;
    persons.push_back( david );
    persons.push_back( ivan );

    // Actual result
    QString actualContent;
    ASSERT_NO_THROW( {
                         parsePersonsToStrContent( persons, actualContent );
                     } );

    // Expected result
    QString expectedContent = "David White\n"
            "Ivan Green\n";

    // Check the actual result
    ASSERT_EQ( expectedContent.toStdString( ),
               actualContent.toStdString( ) );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
