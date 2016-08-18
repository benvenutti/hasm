#ifndef HASM_ASSEMBLER_H_
#define HASM_ASSEMBLER_H_

#include <iostream>
#include <map>
#include <string>

#include "Hack.h"
#include "Parser.h"
#include "SymbolTable.h"

namespace Hasm {
  class Assembler {
    public:
      Assembler(std::istream& in, std::ostream& out);

      void assemble();
      const SymbolTable& getSymbolTable() const;

    private:
      void firstPass();
      void secondPass();
      void assembleACommand();
      void assembleCCommand();
      void output(Hack::WORD word);
      void mapPredefinedSymbols();

      std::ostream& out;
      Parser parser;
      SymbolTable symbolTable;
      Hack::WORD RAMaddress = Hack::INIT_RAM_ADDRESS;
      std::map<std::string, int> predefinedSymbols;
  };
}

#endif
