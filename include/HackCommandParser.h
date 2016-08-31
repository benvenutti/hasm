#ifndef HASM_HACKCOMMANDPARSER_H
#define HASM_HACKCOMMANDPARSER_H

#include <string>

namespace Hasm {
  namespace HackCommandParser {
    bool isComputationCommand(const std::string& cmd);
    bool isLabelCommand(const std::string& cmd);
  };
}

#endif