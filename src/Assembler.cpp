#include "Assembler.hpp"

#include <bitset>
#include <cctype>
#include <iomanip>

#include "Coder.hpp"
#include "ErrorMessage.hpp"

namespace Hasm {

Assembler::Assembler(std::istream& in, std::ostream& out)
    : out(out), parser(in) {}

bool Assembler::assemble() {
  return firstPass() && parser.reset() && secondPass();
}

const SymbolTable& Assembler::getSymbolTable() const {
  return symbolTable;
}

bool Assembler::firstPass() {
  Hack::WORD lineCounter{0};

  while (parser.advance()) {
    if (parser.getCommandType() == CommandType::LABEL) {
      symbolTable.addEntry(parser.symbol(), lineCounter);
    } else {
      lineCounter++;
    }
  }

  return parser.getStatus() == Parser::Status::END_OF_FILE;
}

bool Assembler::secondPass() {
  bool ok{true};

  while (ok && parser.advance()) {
    const auto commandType = parser.getCommandType();
    ok = assembleCommand(commandType);
  }

  return ok;
}

bool Assembler::assembleCommand(const CommandType commandType) {
  switch (commandType) {
    case CommandType::ADDRESSING:
      return assembleACommand();
    case CommandType::COMPUTATION:
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
    displayInvalidACommandMessage();
  }

  return isValid;
}

void Assembler::displayInvalidACommandMessage() {
  const auto cmd = parser.getCommand();
  const auto lineNumber = parser.getCurrentLineNumber();
  std::cerr << ErrorMessage::invalidLoadValue(cmd, lineNumber) << std::endl;
}

bool Assembler::assembleCCommand() {
  Hack::WORD cc{0};

  cc = Coder::dest(parser.dest())
      | Coder::comp(parser.comp())
      | Coder::jump(parser.jump())
      | static_cast<Hack::WORD>(0b1110000000000000);

  output(cc);

  return true;
}

Hack::WORD Assembler::computeValue(const std::string& symbol) {
  Hack::WORD value{0u};

  if (std::isdigit(symbol.front()) != 0) {
    value = static_cast<Hack::WORD>(std::stoi(parser.symbol()));
  } else if (symbolTable.contains(symbol)) {
    value = symbolTable.getAddress(symbol).get();
  } else {
    value = ramAddress++;
    symbolTable.addEntry(symbol, value);
  }

  return value;
}

bool Assembler::isValidValue(const Hack::WORD value) const {
  return value <= MAX_LOADABLE_VALUE;
}

void Assembler::output(const Hack::WORD word) {
  out << std::bitset<16>(word).to_string() << std::endl;
}

} // namespace Hasm