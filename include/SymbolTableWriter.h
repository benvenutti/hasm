#ifndef HASM_SYMBOLTABLEWRITER_H
#define HASM_SYMBOLTABLEWRITER_H

#include <iostream>

namespace Hasm {
  class SymbolTable;

  class SymbolTableWriter {
    public:
      SymbolTableWriter(std::ostream& out, const SymbolTable& symbolTable);

      void write();

    private:
      std::ostream& out;
      const SymbolTable& symbolTable;
  };
}

#endif