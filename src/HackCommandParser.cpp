#include "HackCommandParser.hpp"

#include "HackGrammar.hpp"

#include <regex>

namespace Hasm
{

bool HackCommandParser::isComputationCommand( const std::string& cmd )
{
    static const std::regex regex{ Hack::Grammar::COMPUTATION_COMMAND };

    return std::regex_match( cmd, regex );
}

bool HackCommandParser::isLabelCommand( const std::string& cmd )
{
    static const std::regex regex{ Hack::Grammar::LABEL };

    return std::regex_match( cmd, regex );
}

bool HackCommandParser::isLoadCommand( const std::string& cmd )
{
    static const std::regex regex{ Hack::Grammar::LOAD };

    return std::regex_match( cmd, regex );
}

} // namespace Hasm
