#include "SymbolTable.h"

using Hasm::SymbolTable;

void SymbolTable::addEntry(const std::string& symbol, int address) {
  table.insert(std::pair<std::string, int>(symbol, address));
}

bool SymbolTable::contains(const std::string& symbol) const {
  return table.find(symbol) != table.end();
}

boost::optional<int> SymbolTable::getAddress(const std::string& symbol) const {
  auto it = table.find(symbol);
  if (it != table.end()) {
    return boost::optional<int>(it->second);
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
