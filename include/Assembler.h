#ifndef HASM_ASSEMBLER_H_
#define HASM_ASSEMBLER_H_

#include <iostream>

#include "Hack.hpp"
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
      bool secondPass();
      bool assembleCommand(const Hasm::CommandType commandType);
      bool assembleACommand();
      bool assembleCCommand();
      Hack::WORD computeValue(const std::string& symbol);
      bool isValidValue(const Hack::WORD value) const;
      void output(const Hack::WORD word);

      std::ostream& out;
      Parser parser;
      SymbolTable symbolTable{Hack::PREDEFINED_SYMBOLS};
      Hack::WORD RAMaddress{Hack::INIT_RAM_ADDRESS};
  };
}

#endif
