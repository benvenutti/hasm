#pragma once

#include <string>

namespace Hasm::InstructionParser
{

bool isComputationCommand( const std::string& cmd );
bool isLabelCommand( const std::string& cmd );
bool isLoadCommand( const std::string& cmd );

} // namespace Hasm::InstructionParser
