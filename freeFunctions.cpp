
#include <iostream>
#include <string>
#include <QFile>
#include <QRegExp>
#include <QTextStream>
#include <QDebug>
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

    content = QString( data );
}

void parseContentToPersons( const QString &content, std::vector<Person> &persons )
throw ( EmptyArgument )
{
    std::string functionName = "parseContentToPersons()";

    // Check the input argument
    if ( content.isEmpty( ) ) {
        throw EmptyArgument( functionName );
    }

    QRegExp regExp("(\\w+) (\\w+)");
    int pos = 0;
    while ( ( pos = regExp.indexIn( content, pos ) ) != -1 ) {
        QString firstName = regExp.cap( 1 );
        QString lastName = regExp.cap( 2 );
        Person person( firstName, lastName );
        persons.push_back( person );
        pos += regExp.matchedLength( );
    }
}

void parsePersonsToStrContent( const std::vector<Person> &persons,
                               QString &content)
throw ( EmptyArgument )
{
    std::string functionName = "parsePersonsToStrContent()";

    // Check the input argument
    if ( persons.empty( ) ) {
        throw EmptyArgument( functionName );
    }

    for ( std::size_t i = 0; i < persons.size( ); ++i ) {
        QString firstName = persons[i].firstName( );
        QString lastName = persons[i].lastName( );
        QString line = QString( "%1 %2\n" ).arg( firstName ).arg( lastName );
        content.append( line );
    }
}

void writeData( const QString &fileName, const QString &content )
throw ( EmptyArgument, FileOpenError, FileWriteError )
{
    std::string functionName = "writeData()";

    // Check arguments
    if ( fileName.isEmpty( ) || content.isEmpty( ) ) {
        throw EmptyArgument( functionName );
    }

    // Open the output file for writing
    QFile file( fileName );
    if ( !( file.open( QIODevice::WriteOnly ) ) ) {
        throw FileOpenError( fileName.toStdString( ), functionName );
    }

    // Write data to the output file
    QTextStream stream( &file );
    stream << content;
    if ( stream.status() != QTextStream::Ok ) {
        throw FileWriteError( fileName.toStdString( ), functionName );
    }
}

void printData( const std::vector<Person> &persons )
throw ( EmptyArgument )
{
    std::string functionName = "printData()";

    // Check the input argument
    if ( persons.empty( ) ) {
        throw EmptyArgument( functionName );
    }

    // Print data
    for ( std::size_t i = 0; i < persons.size( ); ++i ) {
        std::cout << "First Name: " << persons[i].firstName( ).toStdString( ) << std::endl;
        std::cout << "Last Name: " << persons[i].lastName( ).toStdString( ) << std::endl;
        std::cout << std::endl;
    }
}
