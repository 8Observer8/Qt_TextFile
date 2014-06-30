
#include "gtest/gtest.h"
#include "Person.h"

TEST( Person_001, constructorFirstNameTest )
{
    Person person( "David", "White" );

    // Actual result
    QString actualFirstName = person.firstName( );
    // Expected result
    QString expectedFirstName = "David";
    // Check the actual result
    ASSERT_EQ( expectedFirstName.toStdString( ), actualFirstName.toStdString( ) );
}

TEST( Person_002, constructorLastNameTest )
{
    Person person( "David", "White" );

    // Actual result
    QString actualLastName = person.lastName( );
    // Expected result
    QString expectedLastName = "White";
    // Check the actual result
    ASSERT_EQ( expectedLastName.toStdString( ), actualLastName.toStdString( ) );
}

TEST( Person_003, setterFirstNameTest )
{
    Person person;
    person.setFirstName( "David" );
    person.setLastName( "White" );

    // Actual result
    QString actualFirstName = person.firstName( );
    // Expected result
    QString expectedFirstName = "David";
    // Check the actual result
    ASSERT_EQ( expectedFirstName.toStdString( ), actualFirstName.toStdString( ) );
}

TEST( Person_004, setterLastNameTest )
{
    Person person;
    person.setFirstName( "David" );
    person.setLastName( "White" );

    // Actual result
    QString actualLastName = person.lastName( );
    // Expected result
    QString expectedLastName = "White";
    // Check the actual result
    ASSERT_EQ( expectedLastName.toStdString( ), actualLastName.toStdString( ) );
}

int main( int argc, char *argv[] )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
