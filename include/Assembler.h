#ifndef HASM_ASSEMBLER_H_
#define HASM_ASSEMBLER_H_

#include "Coder.h"
#include "Parser.h"
#include "SymbolTable.h"

#include <iostream>
#include <map>
#include <string>

namespace Hasm {
  class Assembler {
    public:
      Assembler(std::istream& in, std::ostream& out);

      void assemble();
      const std::map<std::string, int>& symbols() const;

    private:
      void firstPass();
      void secondPass();
      void assembleACommand();
      void assembleCCommand();
      void output(unsigned int value);
      void mapPredefinedSymbols();

      std::istream& in;
      std::ostream& out;
      Parser parser;
      Coder code;
      SymbolTable symbolTable;
      int RAMaddress;
      std::map<std::string, int> predefinedSymbols;
  };
}

#endif
