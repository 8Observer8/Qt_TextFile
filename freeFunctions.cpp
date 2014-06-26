#include <fstream>
#include <sstream>
#include <iostream>

#include <QRegExp>
#include <QFile>
#include <QTextStream>

#include "freeFunctions.h"

void readData(const QString &fileName, QString &content )
throw ( EmptyArgument, FileOpenError, FileReadError )
{
    std::string functionName = "readData()";

    // Check argument
    if ( fileName.isEmpty( ) ) {
        throw EmptyArgument( functionName );
    }

    // Open the input file for reading
    QFile file( fileName );
    if( !file.open( QIODevice::ReadOnly ) ) {
        throw FileOpenError( fileName.toStdString( ), functionName );
    }

    // Read the content from the file
    QByteArray data = file.readAll( );
    if ( data.isEmpty( ) ) {
        throw FileReadError( fileName.toStdString( ), functionName );
    }

    QString tempContent( data );
    content = tempContent;
}

bool isAllDigits( const QString &content )
throw( EmptyArgument )
{
    std::string functionName = "isAllDigits()";

    // Check the input argument
    if ( content.isEmpty( ) ) {
        throw EmptyArgument( functionName );
    }

    bool isDigits = true;

    QRegExp regExp( "\\D" );
    int pos = 0;
    while ( ( pos = regExp.indexIn( content, pos ) ) != -1 ) {
        QRegExp regExpWhiteSpace( "\\s|-" );
        if ( regExpWhiteSpace.indexIn( regExp.cap( 0 ) ) == -1 ) {
            isDigits = false;
            break;
        }

        pos += regExp.matchedLength( );
    }

    return isDigits;
}

void parseToIntArray( const QString &source, std::vector<int> &destination )
throw ( EmptyArgument, OutOfRange, NotNumber )
{
    std::string functionName = "parseToIntArray()";

    // Check the input argument
    if ( source.isEmpty( ) ) {
        throw EmptyArgument( functionName );
    }

    // Is not all digits?
    if ( !isAllDigits( source ) ) {
        throw NotNumber( functionName );
    }

    // Get all digits
    QRegExp regExp( "(\\d+)" );
    int pos = 0;
    while ( ( pos = regExp.indexIn( source, pos ) ) != -1 ) {
        // Get the value
        int value = regExp.cap( 0 ).toInt( );

        // Check for OutOfRange error
        int beginOfRange = -100;
        int endOfRange = 100;
        if ( ( value < beginOfRange ) || ( endOfRange < value ) ) {
            throw OutOfRange( functionName, value, beginOfRange, endOfRange );
        }

        // Save the integer value
        destination.push_back( value );

        pos += regExp.matchedLength( );
    }
}

void writeData(const QString &fileName, const std::vector<int> &arr )
throw ( EmptyArgument, FileOpenError, FileWriteError )
{
    std::string functionName = "writeData()";

    // Check arguments
    if ( fileName.isEmpty( ) || arr.empty( ) ) {
        throw EmptyArgument( functionName );
    }

    // Open the output file for writing
    QFile file( fileName );
    if ( !(file.open( QIODevice::WriteOnly ) ) ) {
        throw FileOpenError( fileName.toStdString( ), functionName );
    }

    // Write data to the output file
    QTextStream stream( &file );
    for ( std::size_t i = 0; i < arr.size( ); i++ ) {
        stream << arr[i] << endl;
        if ( stream.status() != QTextStream::Ok ) {
            throw FileWriteError( fileName.toStdString( ), functionName );
        }
    }
}
