#ifndef HASM_SYMBOLTABLE_HPP
#define HASM_SYMBOLTABLE_HPP

#include <string>
#include <unordered_map>
#include <vector>

#include <boost/optional.hpp>

#include "Hack.hpp"

namespace Hasm {

class SymbolTable {
  public:
    SymbolTable() = default;
    explicit SymbolTable(std::unordered_map<std::string, Hack::WORD> symbols);

    void addEntry(const std::string& symbol, const Hack::WORD address);
    bool contains(const std::string& symbol) const;
    boost::optional<Hack::WORD> getAddress(const std::string& symbol) const;
    std::vector<std::string> getSymbols() const;

  private:
    std::unordered_map<std::string, Hack::WORD> m_table;
};

} // namespace Hasm

#endif
