#include "Assembler.h"

#include <bitset>
#include <iomanip>

#include "Coder.h"
#include "ErrorMessage.h"
#include "Hasm.h"

using Hasm::Assembler;
using Hasm::SymbolTable;

Assembler::Assembler(std::istream& in, std::ostream& out)
    : out(out),
      parser(in) {}

bool Assembler::assemble() {
  return firstPass() && parser.reset() && secondPass();
}

const SymbolTable& Assembler::getSymbolTable() const
{
  return symbolTable;
}

bool Assembler::firstPass() {
  Hack::WORD lineCounter = 0;

  while (parser.advance()) {
    if (parser.getCommandType() == Hasm::CommandType::L_COMMAND) {
      symbolTable.addEntry(parser.symbol(), lineCounter);
    }
    else {
      lineCounter++;
    }
  }

  return parser.getStatus() == Parser::Status::END_OF_FILE;
}

bool Assembler::secondPass() {
  bool ok = true;

  while (ok && parser.advance()) {
    const auto commandType = parser.getCommandType();
    ok = assembleCommand(commandType);
  }

  return ok;
}

bool Assembler::assembleCommand(const Hasm::CommandType commandType) {
  switch (commandType) {
    case Hasm::CommandType::A_COMMAND:
      return assembleACommand();
    case Hasm::CommandType::C_COMMAND:
      return assembleCCommand();
    default:
      return true;
  }
}

bool Assembler::assembleACommand() {
  const auto symbol = parser.symbol();
  const auto value = computeValue(symbol);
  const auto isValid = isValidValue(value);

  if (isValid) {
    output(value);
  } else {
    const auto cmd = parser.getCommand();
    const auto lineNumber = parser.getCurrentLineNumber();
    std::cerr << Hasm::ErrorMessage::invalidLoadValue(cmd, lineNumber) << std::endl;
  }

  return isValid;
}

bool Assembler::assembleCCommand() {
  Hack::WORD cc = 0;

  cc = Coder::dest(parser.dest());
  cc |= Coder::comp(parser.comp());
  cc |= Coder::jump(parser.jump());
  cc |= 0b1110000000000000;

  output(cc);

  return true;
}

Hack::WORD Assembler::computeValue(const std::string& symbol) {
  if (isdigit(symbol.front())) {
    return static_cast<Hack::WORD>(std::stoi(parser.symbol()));
  }
  else if (symbolTable.contains(symbol)) {
    return symbolTable.getAddress(symbol).get();
  }
  else {
    const auto value = RAMaddress++;
    symbolTable.addEntry(symbol, value);

    return value;
  }
}

bool Assembler::isValidValue(const Hack::WORD value) const {
  return value <= Hasm::MAX_LOADABLE_VALUE;
}

void Assembler::output(const Hack::WORD word) {
  out << std::bitset<16>(word).to_string() << std::endl;
}
