#pragma once

#include <string>

namespace Hasm::ErrorMessage
{

[[nodiscard]] std::string invalidInstruction( const std::string& instruction, size_t lineNumber );
[[nodiscard]] std::string invalidLoadValue( const std::string& instruction, size_t lineNumber );

} // namespace Hasm::ErrorMessage
