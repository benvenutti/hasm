#include <hasm/SymbolTable.hpp>

namespace Hasm
{

SymbolTable::SymbolTable( std::unordered_map< std::string, ::Hack::word > symbols )
: m_table{ std::move( symbols ) }
{
}

void SymbolTable::addEntry( const std::string& symbol, const ::Hack::word address )
{
    m_table.emplace( symbol, address );
}

bool SymbolTable::contains( const std::string& symbol ) const
{
    return m_table.find( symbol ) != m_table.end();
}

std::optional< ::Hack::word > SymbolTable::getAddress( const std::string& symbol ) const
{
    if ( const auto it = m_table.find( symbol ); it != m_table.end() )
    {
        return it->second;
    }

    return std::nullopt;
}

} // namespace Hasm
