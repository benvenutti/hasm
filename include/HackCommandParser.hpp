#pragma once

#include <string>

namespace Hasm::HackCommandParser
{

bool isComputationCommand( const std::string& cmd );
bool isLabelCommand( const std::string& cmd );
bool isLoadCommand( const std::string& cmd );

} // namespace Hasm::HackCommandParser
