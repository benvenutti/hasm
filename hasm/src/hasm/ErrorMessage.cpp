#include <hasm/ErrorMessage.hpp>

#include <format>

namespace Hasm
{

namespace
{

std::string message( const std::string& cmd, const int lineNumber, const std::string& info )
{
    return std::format( R"( line {}: error: "{}" {} )", lineNumber, cmd, info );
}

} // namespace

std::string ErrorMessage::invalidCommand( const std::string& cmd, const int lineNumber )
{
    const auto msg = message( cmd, lineNumber, "is an invalid command" );

    return msg;
}

std::string ErrorMessage::invalidLoadValue( const std::string& cmd, const int lineNumber )
{
    const auto msg = message( cmd, lineNumber, "loads a value greater than an unsigned 15-bit number" );

    return msg;
}

} // namespace Hasm
