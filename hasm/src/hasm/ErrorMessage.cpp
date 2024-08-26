#include <hasm/ErrorMessage.hpp>

#include <format>

namespace
{

std::string message( const std::string& cmd, const int lineNumber, const std::string& info )
{
    return std::format( R"( line {}: error: "{}" {} )", lineNumber, cmd, info );
}

} // namespace

namespace Hasm
{

std::string ErrorMessage::invalidCommand( const std::string& cmd, const int lineNumber )
{
    return message( cmd, lineNumber, "is an invalid command" );
}

std::string ErrorMessage::invalidLoadValue( const std::string& cmd, const int lineNumber )
{
    return message( cmd, lineNumber, "loads a value greater than an unsigned 15-bit number" );
}

} // namespace Hasm
