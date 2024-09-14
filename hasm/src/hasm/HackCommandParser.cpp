#include <hasm/HackCommandParser.hpp>

#include <hasm/HackGrammar.hpp>

#include <regex>

namespace Hasm
{

bool HackCommandParser::isComputationCommand( const std::string& cmd )
{
    static const std::regex regex{ Grammar::computation_command };

    return std::regex_match( cmd, regex );
}

bool HackCommandParser::isLabelCommand( const std::string& cmd )
{
    static const std::regex regex{ Grammar::label };

    return std::regex_match( cmd, regex );
}

bool HackCommandParser::isLoadCommand( const std::string& cmd )
{
    static const std::regex regex{ Grammar::load };

    return std::regex_match( cmd, regex );
}

} // namespace Hasm
