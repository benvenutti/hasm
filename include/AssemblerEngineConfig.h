#ifndef HASM_ASSEMBLERENGINECONFIG_H_
#define HASM_ASSEMBLERENGINECONFIG_H_

#include <string>

namespace Hasm {
  class AssemblerEngineConfig {
    public:
      AssemblerEngineConfig(bool isValid, bool isVerbose, bool exportSymbols, std::string inputName)
          : isValid{isValid}, isVerbose{isVerbose}, exportSymbols{exportSymbols}, inputName{inputName} { }

      const bool isValid;
      const bool isVerbose;
      const bool exportSymbols;
      const std::string inputName;
  };
}

#endif
