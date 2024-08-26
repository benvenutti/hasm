#pragma once

#include <string>

namespace Hasm::ErrorMessage
{

std::string invalidCommand( const std::string& cmd, const int lineNumber );
std::string invalidLoadValue( const std::string& cmd, const int lineNumber );

} // namespace Hasm::ErrorMessage
