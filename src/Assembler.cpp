#include "Assembler.h"

#include "Coder.h"

#include <bitset>
#include <iomanip>

using Hasm::Assembler;

Assembler::Assembler(std::istream& in, std::ostream& out)
    : in(in),
      out(out),
      parser(in),
      symbolTable(),
      RAMaddress(Hasm::INIT_RAM_ADDRESS),
      predefinedSymbols() {
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
  predefinedSymbols.insert(std::pair<std::string, int>("SP", 0x00));
  predefinedSymbols.insert(std::pair<std::string, int>("LCL", 0x01));
  predefinedSymbols.insert(std::pair<std::string, int>("ARG", 0x02));
  predefinedSymbols.insert(std::pair<std::string, int>("THIS", 0x03));
  predefinedSymbols.insert(std::pair<std::string, int>("THAT", 0x04));

  for (int i = 0; i < 16; i++) {
    std::string reg("R" + std::to_string(i));
    predefinedSymbols.insert(std::pair<std::string, int>(reg, i));
  }

  predefinedSymbols.insert(std::pair<std::string, int>("SCREEN", 0x4000));
  predefinedSymbols.insert(std::pair<std::string, int>("KBD", 0x6000));

  symbolTable.setTable(predefinedSymbols);
}
