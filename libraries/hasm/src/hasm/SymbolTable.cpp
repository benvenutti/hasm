#include <hasm/SymbolTable.hpp>

namespace Hasm
{

SymbolTable::SymbolTable( std::unordered_map< std::string, Hack::word > symbols )
: m_table{ std::move( symbols ) }
{
}

bool SymbolTable::addEntry( const std::string& symbol, const Hack::word address )
{
    return m_table.emplace( symbol, address ).second;
}

bool SymbolTable::contains( const std::string& symbol ) const
{
    return m_table.contains( symbol );
}

std::optional< Hack::word > SymbolTable::getAddress( const std::string& symbol ) const
{
    if ( const auto it = m_table.find( symbol ); it != m_table.end() )
    {
        return it->second;
    }

    return std::nullopt;
}

} // namespace Hasm
