#include <hasm/InstructionParser.hpp>

#include <hasm/HackGrammar.hpp>

#include <regex>

namespace Hasm
{

bool InstructionParser::isComputation( const std::string& instruction )
{
    static const std::regex regex{ Grammar::computation_command };

    return std::regex_match( instruction, regex );
}

bool InstructionParser::isLabel( const std::string& instruction )
{
    static const std::regex regex{ Grammar::label };

    return std::regex_match( instruction, regex );
}

bool InstructionParser::isLoad( const std::string& instruction )
{
    static const std::regex regex{ Grammar::load };

    return std::regex_match( instruction, regex );
}

} // namespace Hasm
