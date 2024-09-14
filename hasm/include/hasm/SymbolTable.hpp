#pragma once

#include <Hack/Hack.hpp>

#include <optional>
#include <string>
#include <unordered_map>

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

    [[nodiscard]] inline auto begin() noexcept
    {
        return m_table.begin();
    }

    [[nodiscard]] inline auto begin() const noexcept
    {
        return m_table.begin();
    }

    [[nodiscard]] inline auto end() noexcept
    {
        return m_table.end();
    }

    [[nodiscard]] inline auto end() const noexcept
    {
        return m_table.end();
    }

private:
    std::unordered_map< std::string, Hack::word > m_table;
};

} // namespace Hasm
