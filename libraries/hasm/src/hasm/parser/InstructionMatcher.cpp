#include <hasm/parser/InstructionMatcher.hpp>

namespace Hasm::Parser
{

bool matchesLabel( std::string_view )
{
    return false;
}

bool matchesAddressInstruction( std::string_view )
{
    return false;
}

} // namespace Hasm::Parser
