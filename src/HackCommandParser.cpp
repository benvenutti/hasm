#include "HackCommandParser.hpp"

#include <boost/regex.hpp>

#include "HackGrammar.hpp"

namespace {
  const boost::regex labelCmdRegex{Hack::Grammar::LABEL};
  const boost::regex compCmdRegex{Hack::Grammar::COMPUTATION_COMMAND};
  const boost::regex loadCmdRegex{Hack::Grammar::LOAD};
}

bool Hasm::HackCommandParser::isComputationCommand(const std::string& cmd) {
  return boost::regex_match(cmd, compCmdRegex);
}

bool Hasm::HackCommandParser::isLabelCommand(const std::string& cmd) {
  return boost::regex_match(cmd, labelCmdRegex);
}

bool Hasm::HackCommandParser::isLoadCommand(const std::string& cmd) {
  return boost::regex_match(cmd, loadCmdRegex);
}