#ifndef HASM_ASSEMBLERENGINECONFIG_H_
#define HASM_ASSEMBLERENGINECONFIG_H_

#include <string>

namespace Hasm {
  class AssemblerEngineConfig {
    public:
      AssemblerEngineConfig(bool isValid, bool exportSymbols, std::string inputName)
          : isValid{isValid}, exportSymbols{exportSymbols}, inputName{inputName} { }

      const bool isValid;
      const bool exportSymbols;
      const std::string inputName;
  };
}

#endif
