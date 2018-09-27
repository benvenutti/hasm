#pragma once

#include <string>

namespace Hasm
{
namespace HackCommandParser
{

bool isComputationCommand( const std::string& cmd );
bool isLabelCommand( const std::string& cmd );
bool isLoadCommand( const std::string& cmd );

} // namespace HackCommandParser
} // namespace Hasm
