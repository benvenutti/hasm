#include "HackCommandParser.hpp"

#include "HackGrammar.hpp"

#include <regex>

namespace Hasm
{

namespace
{

const std::regex labelCmdRegex{ Hack::Grammar::LABEL };
const std::regex compCmdRegex{ Hack::Grammar::COMPUTATION_COMMAND };
const std::regex loadCmdRegex{ Hack::Grammar::LOAD };

} // namespace

bool HackCommandParser::isComputationCommand( const std::string& cmd )
{
    return std::regex_match( cmd, compCmdRegex );
}

bool HackCommandParser::isLabelCommand( const std::string& cmd )
{
    return std::regex_match( cmd, labelCmdRegex );
}

bool HackCommandParser::isLoadCommand( const std::string& cmd )
{
    return std::regex_match( cmd, loadCmdRegex );
}

} // namespace Hasm
