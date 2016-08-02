#ifndef HASM_SYMBOLTABLE_H_
#define HASM_SYMBOLTABLE_H_

#include <map>
#include <string>

namespace Hasm {
  class SymbolTable {
    public:
      void addEntry(const std::string& symbol, int address);
      bool contains(const std::string& symbol) const;
      int getAddress(const std::string& symbol) const;
      const std::map<std::string, int>& getTable() const;

    private:
      std::map<std::string, int> table;
  };
}

#endif
