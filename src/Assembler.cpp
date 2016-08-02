#include "Assembler.h"

#include "Coder.h"
#include "Hasm.h"

#include <bitset>
#include <iomanip>

using Hasm::Assembler;

Assembler::Assembler(std::istream& in, std::ostream& out)
    : out(out),
      parser(in) {
  mapPredefinedSymbols();
}

void Assembler::assemble() {
  firstPass();
  parser.reset();
  secondPass();
}

const std::map<std::string, int>& Assembler::symbols() const {
  return symbolTable.getTable();
}

void Assembler::firstPass() {
  int lineCounter = 0;

  while (parser.advance()) {
    if (parser.getCommandType() == Hasm::HasmCommandType::L_COMMAND) {
      symbolTable.addEntry(parser.symbol(), lineCounter);
    }
    else {
      lineCounter++;
    }
  }
}

void Assembler::secondPass() {
  while (parser.advance()) {
    Hasm::HasmCommandType cmdType = parser.getCommandType();

    if (cmdType == Hasm::HasmCommandType::A_COMMAND) {
      assembleACommand();
    }
    else if (cmdType == Hasm::HasmCommandType::C_COMMAND) {
      assembleCCommand();
    }
  }
}

void Assembler::assembleACommand() {
  std::string symbol = parser.symbol();
  unsigned int value;

  if (isdigit(symbol.front())) {
    value = stoi(parser.symbol());
  }
  else if (symbolTable.contains(symbol)) {
    value = symbolTable.getAddress(symbol);
  }
  else {
    symbolTable.addEntry(symbol, RAMaddress);
    value = RAMaddress++;
  }

  output(value);
}

void Assembler::assembleCCommand() {
  unsigned int cc = 0;

  cc = Coder::dest(parser.dest());
  cc |= Coder::comp(parser.comp());
  cc |= Coder::jump(parser.jump());
  cc |= 0b1110000000000000;

  output(cc);
}

void Assembler::output(unsigned int value) {
  out << std::bitset<16>(value).to_string() << std::endl;
}

void Assembler::mapPredefinedSymbols() {
  symbolTable.addEntry("SP", 0x00);
  symbolTable.addEntry("LCL", 0x01);
  symbolTable.addEntry("ARG", 0x02);
  symbolTable.addEntry("THIS", 0x03);
  symbolTable.addEntry("THAT", 0x04);

  for (int i = 0; i < 16; i++) {
    std::string reg("R" + std::to_string(i));
    symbolTable.addEntry(reg, i);
  }

  symbolTable.addEntry("SCREEN", 0x4000);
  symbolTable.addEntry("KBD", 0x6000);
}
