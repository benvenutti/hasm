#include "Assembler.h"

#include "Coder.h"
#include "Hasm.h"

#include <bitset>
#include <iomanip>

using Hasm::Assembler;
using Hasm::SymbolTable;

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

const SymbolTable& Assembler::getSymbolTable() const
{
  return symbolTable;
}

void Assembler::firstPass() {
  Hack::WORD lineCounter = 0;

  while (parser.advance()) {
    if (parser.getCommandType() == Hasm::CommandType::L_COMMAND) {
      symbolTable.addEntry(parser.symbol(), lineCounter);
    }
    else {
      lineCounter++;
    }
  }
}

void Assembler::secondPass() {
  while (parser.advance()) {
    Hasm::CommandType cmdType = parser.getCommandType();

    if (cmdType == Hasm::CommandType::A_COMMAND) {
      assembleACommand();
    }
    else if (cmdType == Hasm::CommandType::C_COMMAND) {
      assembleCCommand();
    }
  }
}

void Assembler::assembleACommand() {
  std::string symbol = parser.symbol();
  Hack::WORD value;

  if (isdigit(symbol.front())) {
    value = static_cast<Hack::WORD>(stoi(parser.symbol()));
  }
  else if (symbolTable.contains(symbol)) {
    boost::optional<Hack::WORD> address = symbolTable.getAddress(symbol);
    value = address.get();
  }
  else {
    symbolTable.addEntry(symbol, RAMaddress);
    value = RAMaddress++;
  }

  output(value);
}

void Assembler::assembleCCommand() {
  Hack::WORD cc = 0;

  cc = Coder::dest(parser.dest());
  cc |= Coder::comp(parser.comp());
  cc |= Coder::jump(parser.jump());
  cc |= 0b1110000000000000;

  output(cc);
}

void Assembler::output(Hack::WORD word) {
  out << std::bitset<16>(word).to_string() << std::endl;
}

void Assembler::mapPredefinedSymbols() {
  for (const auto& it: Hack::PREDEFINED_SYMBOLS) {
    symbolTable.addEntry(it.first, it.second);
  }
}
