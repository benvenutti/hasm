#pragma once

#include <hasm/Hack.hpp>

#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Hasm
{

class SymbolTable
{
public:
    SymbolTable() = default;
    explicit SymbolTable( std::unordered_map< std::string, Hack::word > symbols );

    void addEntry( const std::string& symbol, const Hack::word address );

    [[nodiscard]] bool contains( const std::string& symbol ) const;

    [[nodiscard]] std::optional< Hack::word > getAddress( const std::string& symbol ) const;

    [[nodiscard]] std::vector< std::string > getSymbols() const;

private:
    std::unordered_map< std::string, Hack::word > m_table;
};

} // namespace Hasm
