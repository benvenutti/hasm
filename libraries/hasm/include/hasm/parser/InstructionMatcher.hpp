#pragma once

#include <string_view>

namespace Hasm::Parser
{

/// Returns whether the given text matches the syntax of a label declaration.
bool matchesLabel( std::string_view );

/// Returns whether the given text matches the syntax of an A-instruction.
bool matchesAddressInstruction( std::string_view );

} // namespace Hasm::Parser
