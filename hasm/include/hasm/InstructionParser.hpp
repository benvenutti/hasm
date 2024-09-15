#pragma once

#include <string>

namespace Hasm::InstructionParser
{

bool isComputation( const std::string& instruction );
bool isLabel( const std::string& instruction );
bool isLoad( const std::string& instruction );

} // namespace Hasm::InstructionParser
