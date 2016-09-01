#include "SymbolTable.h"

using Hasm::SymbolTable;

void SymbolTable::addEntry(const std::string& symbol, Hack::WORD address) {
  table.insert(std::make_pair(symbol, address));
}

bool SymbolTable::contains(const std::string& symbol) const {
  return table.find(symbol) != table.end();
}

boost::optional<Hack::WORD> SymbolTable::getAddress(const std::string& symbol) const {
  auto it = table.find(symbol);
  if (it != table.end()) {
    return boost::optional<Hack::WORD>(it->second);
  }

  return boost::none;
}

std::set<std::string> SymbolTable::getSymbols() const
{
  std::set<std::string> symbols;
  for (auto it: table) {
    symbols.insert(it.first);
  }

  return symbols;
}
