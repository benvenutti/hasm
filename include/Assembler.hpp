#ifndef HASM_ASSEMBLER_HPP
#define HASM_ASSEMBLER_HPP

#include <iostream>

#include "Hack.hpp"
#include "Hasm.hpp"
#include "Parser.hpp"
#include "SymbolTable.hpp"

namespace Hasm {

class Assembler {
  public:
    Assembler(std::istream& in, std::ostream& out);

    bool assemble();
    const SymbolTable& getSymbolTable() const;

  private:
    bool firstPass();
    bool secondPass();
    bool assembleCommand(const CommandType commandType);
    bool assembleACommand();
    bool assembleCCommand();
    Hack::WORD computeValue(const std::string& symbol);
    bool isValidValue(const Hack::WORD value) const;
    void output(const Hack::WORD word);
    void displayInvalidACommandMessage();

    std::ostream& out;
    Parser parser;
    SymbolTable symbolTable{Hack::PREDEFINED_SYMBOLS};
    Hack::WORD ramAddress{Hack::INIT_RAM_ADDRESS};
};

} // namespace Hasm

#endif
