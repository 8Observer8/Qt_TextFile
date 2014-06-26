#ifndef OUTOFRANGE_H
#define OUTOFRANGE_H

#include <string>
#include <sstream>
#include "LogicError.h"

class OutOfRange : public LogicError {
public:

    OutOfRange( const std::string &functionName,
                int argument,
                int beginOfRange,
                int endOfRange ) :
        LogicError( functionName )
    {
        // Convert arguments from int to std::string
        std::string strArgument, strBeginOfRange, strEndOfRange;
        strArgument = intToString( argument );
        strBeginOfRange = intToString( beginOfRange );
        strEndOfRange = intToString( endOfRange );

        m_message = "Error: the argument \"" + strArgument +
                "\" doesn't hit into the range [" +
                strBeginOfRange + ", " + strEndOfRange + "]";
    }

private:
    std::string intToString( int number )
    {
        std::stringstream stream;
        stream << number;
        return stream.str( );
    }
};

#endif // OUTOFRANGE_H
