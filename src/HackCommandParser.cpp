#include "HackCommandParser.h"

#include <boost/regex.hpp>

#include "HackGrammar.h"

namespace {
  const boost::regex compCmdRegex{Hack::Grammar::COMPUTATION_COMMAND};
}

bool Hasm::HackCommandParser::isComputationCommand(const std::string& cmd) {
  return boost::regex_match(cmd, compCmdRegex);
}