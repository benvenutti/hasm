#pragma once

#include <string>

namespace Hasm::ErrorMessage
{

[[nodiscard]] std::string invalidCommand( const std::string& cmd, int lineNumber );
[[nodiscard]] std::string invalidLoadValue( const std::string& cmd, int lineNumber );

} // namespace Hasm::ErrorMessage
