#pragma once

#include <string>

namespace Hasm::ErrorMessage
{

[[nodiscard]] std::string invalidCommand( const std::string& cmd, size_t lineNumber );
[[nodiscard]] std::string invalidLoadValue( const std::string& cmd, size_t lineNumber );

} // namespace Hasm::ErrorMessage
