
#include <iostream>
#include <vector>
#include <QString>
#include "freeFunctions.h"
#include "Person.h"

int main( )
{
    // Person array for saving
    Person david( "David", "White");
    Person ivan( "Ivan", "Green" );
    std::vector<Person> persons;
    persons.push_back( david );
    persons.push_back( ivan );

    try {
        // Parse the person array to the string content
        QString content;
        parsePersonsToStrContent( persons, content );

        // Save the string content to the file
        QString fileName = "file.txt";
        writeData( fileName, content );

        // Read the string content from the file
        QString readContent;
        readData( fileName, readContent );

        // Parse the string content to the person array
        std::vector<Person> readPersons;
        parseContentToPersons( readContent, readPersons );

        // Print the person array on the screen
        printData( readPersons );
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

    return 0;
}
