#include "SymbolTable.hpp"

namespace Hasm {

SymbolTable::SymbolTable(std::unordered_map<std::string, Hack::WORD> symbols)
    : table{std::move(symbols)} {}

void SymbolTable::addEntry(const std::string& symbol, const Hack::WORD address) {
  table.emplace(symbol, address);
}

bool SymbolTable::contains(const std::string& symbol) const {
  const auto hasSymbol = table.find(symbol) != table.end();

  return hasSymbol;
}

boost::optional<Hack::WORD> SymbolTable::getAddress(const std::string& symbol) const {
  const auto it = table.find(symbol);
  if (it != table.end()) {
    const auto address = boost::optional<Hack::WORD>(it->second);

    return address;
  }

  return boost::none;
}

std::set<std::string> SymbolTable::getSymbols() const {
  std::set<std::string> symbols{};
  for (const auto& it: table) {
    symbols.insert(it.first);
  }

  return symbols;
}

} // namespace Hasm