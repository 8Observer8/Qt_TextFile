#include <iostream>
#include <string>
#include <vector>
#include <QString>
#include "freeFunctions.h"
#include "LogicError.h"
#include "FileError.h"

int main( )
{
    // Read data from the input file
    QString fileNameIn = "input.txt";
    QString content;

    try {
        readData( fileNameIn, content );
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

    // Parse the content to the integer array
    std::vector<int> arr;
    try {
        parseToIntArray( content, arr );
    } catch ( const LogicError &e ) {
        std::cerr << e.what( ) << std::endl;
        return 1;
    } catch ( ... ) {
        std::cerr << "Error: unknown exception" << std::endl;
        return 1;
    }

    // Write data to the output file
    QString fileNameOut = "output.txt";
    try {
        writeData( fileNameOut, arr );
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
