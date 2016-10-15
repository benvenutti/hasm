#ifndef HASM_ASSEMBLER_H_
#define HASM_ASSEMBLER_H_

#include <iostream>

#include "Hack.h"
#include "Parser.h"
#include "SymbolTable.h"

namespace Hasm {
  class Assembler {
    public:
      Assembler(std::istream& in, std::ostream& out);

      bool assemble();
      const SymbolTable& getSymbolTable() const;

    private:
      bool firstPass();
      void secondPass();
      void assembleACommand();
      void assembleCCommand();
      void output(const Hack::WORD word);

      std::ostream& out;
      Parser parser;
      SymbolTable symbolTable{Hack::PREDEFINED_SYMBOLS};
      Hack::WORD RAMaddress{Hack::INIT_RAM_ADDRESS};
  };
}

#endif
