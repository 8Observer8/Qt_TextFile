
#include "gtest/gtest.h"
#include "freeFunctions.h"

TEST( parseContentToPersons_001, EmptyArgumentTest )
{
    // Input data
    QString content = "";

    // Actual result
    std::vector<Person> persons;
    ASSERT_THROW( {
                      parseContentToPersons( content, persons );
                  }, EmptyArgument );
}

TEST( parseContentToPersons_002, firstNameOfFirstPerson )
{
    // Input data
    QString content = "David White\n"
            "Ivan Green";

    // Get the actual result
    std::vector<Person> persons;
    ASSERT_NO_THROW( {
                         parseContentToPersons( content, persons );
                     } );

    // Check the actual size
    std::size_t expectedSize = 2;
    std::size_t actualSize = persons.size( );
    ASSERT_EQ( expectedSize, actualSize );

    // Actual result
    QString actual = persons[0].firstName( );

    // Expected result
    QString expected = "David";

    // Check the actual result
    ASSERT_EQ( expected.toStdString( ), actual.toStdString( ));
}

TEST( parseContentToPersons_003, lastNameOfFirstPerson )
{
    // Input data
    QString content = "David White\n"
            "Ivan Green";

    // Get the actual result
    std::vector<Person> persons;
    ASSERT_NO_THROW( {
                      parseContentToPersons( content, persons );
                  } );

    // Check the actual size
    std::size_t expectedSize = 2;
    std::size_t actualSize = persons.size( );
    ASSERT_EQ( expectedSize, actualSize );

    // Actual result
    QString actual = persons[0].lastName( );

    // Expected result
    QString expected = "White";

    // Check the actual result
    ASSERT_EQ( expected.toStdString( ), actual.toStdString( ) );
}

TEST( parseContentToPersons_004, firstNameOfSecondPerson )
{
    // Input data
    QString content = "David White\n"
            "Ivan Green";

    // Get the actual result
    std::vector<Person> persons;
    ASSERT_NO_THROW( {
                         parseContentToPersons( content, persons );
                     } );

    // Check the actual size
    std::size_t expectedSize = 2;
    std::size_t actualSize = persons.size( );
    ASSERT_EQ( expectedSize, actualSize );

    // Actual result
    QString actual = persons[1].firstName( );

    // Expected result
    QString expected = "Ivan";

    // Check the actual result
    ASSERT_EQ( expected.toStdString( ), actual.toStdString( ) );
}

TEST( parseContentToPersons_005, lastNameOfSecondPerson )
{
    // Input data
    QString content = "David White\n"
            "Ivan Green";

    // Get the actual result
    std::vector<Person> persons;
    ASSERT_NO_THROW( {
                         parseContentToPersons( content, persons );
                     } );

    // Check the actual size
    std::size_t expectedSize = 2;
    std::size_t actualSize = persons.size( );
    ASSERT_EQ( expectedSize, actualSize );

    // Actual result
    QString actual = persons[1].lastName( );

    // Expected result
    QString expected = "Green";

    // Check the actual result
    ASSERT_EQ( expected.toStdString( ), actual.toStdString( ) );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
