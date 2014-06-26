#ifndef FREEFUNCTIONS_H
#define FREEFUNCTIONS_H

#include <string>
#include <vector>

#include <QString>

#include "FileOpenError.h"
#include "FileReadError.h"
#include "FileWriteError.h"
#include "EmptyArgument.h"
#include "OutOfRange.h"
#include "NotNumber.h"

void readData( const QString &fileName, QString &content )
throw ( EmptyArgument, FileOpenError, FileReadError );

void parseToIntArray( const QString &source, std::vector<int> &destination )
throw ( EmptyArgument, OutOfRange, NotNumber );

bool isAllDigits( const QString &content )
throw ( EmptyArgument );

void writeData( const QString &fileName, const std::vector<int> &arr )
throw ( EmptyArgument, FileOpenError, FileWriteError );

#endif // FREEFUNCTIONS_H
