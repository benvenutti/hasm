#ifndef HASM_ASSEMBLERENGINE_H_
#define HASM_ASSEMBLERENGINE_H_

#include <iostream>
#include <string>

namespace Hasm {
  class AssemblerEngineConfig;
  class SymbolTable;

  class AssemblerEngine {
    public:
      bool run(int argc, char** argv) const;

    private:
      bool isAsmFile(const std::string& fileName) const;
      bool exportSymbolTable(const AssemblerEngineConfig& cfg, const SymbolTable& table) const;
      void outputSymbolTable(std::ostream& out, const SymbolTable& table) const;
  };
}

#endif
