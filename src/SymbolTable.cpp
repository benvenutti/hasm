#include "SymbolTable.h"

using Hasm::SymbolTable;

void SymbolTable::addEntry(const std::string& symbol, int address) {
  table.insert(std::pair<std::string, int>(symbol, address));
}

bool SymbolTable::contains(const std::string& symbol) const {
  return table.find(symbol) != table.end();
}

int SymbolTable::getAddress(const std::string& symbol) const {
  auto it = table.find(symbol);

  return it != table.end() ? it->second : -1;
}

const std::map<std::string, int>& SymbolTable::getTable() const {
  return table;
}
