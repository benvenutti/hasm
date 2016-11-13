#ifndef HASM_SYMBOLTABLEWRITER_HPP
#define HASM_SYMBOLTABLEWRITER_HPP

#include <ostream>

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

} // namespace Hasm

#endif