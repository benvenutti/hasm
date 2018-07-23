#include "HackCommandParser.hpp"

#include "HackGrammar.hpp"

#include <boost/regex.hpp>

namespace Hasm
{

namespace
{

const boost::regex labelCmdRegex{ Hack::Grammar::LABEL };
const boost::regex compCmdRegex{ Hack::Grammar::COMPUTATION_COMMAND };
const boost::regex loadCmdRegex{ Hack::Grammar::LOAD };

} // namespace

bool HackCommandParser::isComputationCommand( const std::string& cmd )
{
    return boost::regex_match( cmd, compCmdRegex );
}

bool HackCommandParser::isLabelCommand( const std::string& cmd )
{
    return boost::regex_match( cmd, labelCmdRegex );
}

bool HackCommandParser::isLoadCommand( const std::string& cmd )
{
    return boost::regex_match( cmd, loadCmdRegex );
}

} // namespace Hasm
