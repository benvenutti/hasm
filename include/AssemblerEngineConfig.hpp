#ifndef HASM_ASSEMBLERENGINECONFIG_HPP
#define HASM_ASSEMBLERENGINECONFIG_HPP

#include <string>

namespace Hasm {

class AssemblerEngineConfig {
  public:
    AssemblerEngineConfig(const bool isValid, const bool exportSymbols, std::string inputName)
        : isValid{isValid}, exportSymbols{exportSymbols}, inputName{inputName} {}

    const bool isValid;
    const bool exportSymbols;
    const std::string inputName;
};

} // namespace Hasm

#endif
