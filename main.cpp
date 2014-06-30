#include <iostream>
#include <vector>
#include <QString>
#include "freeFunctions.h"

int main( )
{
    // Person array for saving
    Person david( "David", "White");
    Person ivan( "Ivan", "Green" );
    std::vector<Person> persons;
    persons.push_back( david );
    persons.push_back( ivan );

    // Parse the person array to the string content
    QString content;
    try {
        parsePersonsToStrContent( persons, content );
    } catch( const LogicError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch( ... ) {
        std::cerr << "Error: unknown exception" << std::endl;
        return 1;
    }

    // Save the string content to the file
    QString fileName = "file.txt";
    try {
        writeData( fileName, content );
    } catch ( const LogicError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( const FileError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( ... ) {
        std::cerr << "Error: unknown exception" << std::endl;
        return 1;
    }

    // Read the string content from the file
    QString readContent;
    try {
        readData( fileName, readContent );
    } catch ( const LogicError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( const FileError &e) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( ... ) {
        std::cerr << "Error: unknown exception" << std::endl;
        return 1;
    }

    // Parse the string content to the person array
    std::vector<Person> readPersons;
    try {
        parseContentToPersons( readContent, readPersons );
    } catch( const LogicError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch( ... ) {
        std::cerr << "Error: unknown exception" << std::endl;
        return 1;
    }

    // Print the person array on the screen
    try {
        printData( readPersons );
    } catch( const LogicError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( ... ) {
        std::cerr << "Error: unknown exception" << std::endl;
        return 1;
    }

    return 0;
}
