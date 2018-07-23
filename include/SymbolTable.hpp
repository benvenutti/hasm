#pragma once

#include "Hack.hpp"

#include <boost/optional.hpp>

#include <string>
#include <unordered_map>
#include <vector>

namespace Hasm
{

class SymbolTable
{
public:
    SymbolTable() = default;
    explicit SymbolTable( std::unordered_map<std::string, Hack::word> symbols );

    void                        addEntry( const std::string& symbol, const Hack::word address );
    bool                        contains( const std::string& symbol ) const;
    boost::optional<Hack::word> getAddress( const std::string& symbol ) const;
    std::vector<std::string>    getSymbols() const;

private:
    std::unordered_map<std::string, Hack::word> m_table;
};

} // namespace Hasm
