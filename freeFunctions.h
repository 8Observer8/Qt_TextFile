#ifndef FREEFUNCTIONS_H
#define FREEFUNCTIONS_H

#include <vector>

#include <QString>

#include "FileOpenError.h"
#include "FileReadError.h"
#include "FileWriteError.h"
#include "EmptyArgument.h"
#include "Person.h"

void readData( const QString &fileName, QString &content )
throw ( EmptyArgument, FileOpenError, FileReadError );

void parseContentToPersons( const QString &content,
                            std::vector<Person> &persons )
throw ( EmptyArgument );

void parsePersonsToStrContent( const std::vector<Person> &persons,
                               QString &content)
throw ( EmptyArgument );

void writeData( const QString &fileName,
                const QString &content )
throw ( EmptyArgument, FileOpenError, FileWriteError );

void printData( const std::vector<Person> &persons )
throw ( EmptyArgument );

#endif // FREEFUNCTIONS_H
