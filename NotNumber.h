#ifndef NOTNUMBER_H
#define NOTNUMBER_H

#include <string>
#include "LogicError.h"

class NotNumber : public LogicError
{
public:
    NotNumber( const std::string &functionName ) :
        LogicError( functionName )
    {
        m_message = "Error: the argument in the function \"" +
                functionName + "\" must contain only numbers";
    }
};

#endif // NOTNUMBER_H
