#include <hasm/parser/InstructionMatcher.hpp>

#include <hasm/language/Grammar.hpp>

#include <regex>

namespace Hasm::Parser
{

bool matchesLabel( const std::string_view text )
{
    return std::regex_match( text.begin(), text.end(), Language::Grammar::label );
}

bool matchesAddressInstruction( const std::string_view text )
{
    return std::regex_match( text.begin(), text.end(), Language::Grammar::addressInstruction );
}

} // namespace Hasm::Parser
