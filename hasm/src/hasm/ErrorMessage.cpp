#include <hasm/ErrorMessage.hpp>

#include <format>

namespace
{

std::string createMessage( const std::string& instruction, const size_t lineNumber, const std::string& info )
{
    return std::format( R"(line {}: error: "{}" {})", lineNumber, instruction, info );
}

} // namespace

namespace Hasm
{

std::string ErrorMessage::invalidInstruction( const std::string& instruction, const size_t lineNumber )
{
    return createMessage( instruction, lineNumber, "is an invalid command" );
}

std::string ErrorMessage::invalidLoadValue( const std::string& instruction, const size_t lineNumber )
{
    return createMessage( instruction, lineNumber, "loads a value greater than an unsigned 15-bit number" );
}

} // namespace Hasm
