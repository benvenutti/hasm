#ifndef HASM_ASSEMBLERENGINE_H_
#define HASM_ASSEMBLERENGINE_H_

#include <iostream>
#include <map>
#include <string>

namespace Hasm {
  class AssemblerEngine {
    public:
      bool run(int argc, char** argv) const;

    private:
      bool isAsmFile(const std::string& fileName) const;
      void outputSymbolTable(std::ostream& out, const std::map<std::string, int>& table) const;
  };
}

#endif
