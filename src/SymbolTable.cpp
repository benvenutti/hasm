#include "SymbolTable.hpp"

//#include <boost/range/adaptors.hpp>

namespace Hasm
{

SymbolTable::SymbolTable( std::unordered_map<std::string, Hack::word> symbols )
: m_table{ std::move( symbols ) }
{
}

void SymbolTable::addEntry( const std::string& symbol, const Hack::word address )
{
    m_table.emplace( symbol, address );
}

bool SymbolTable::contains( const std::string& symbol ) const
{
    return m_table.find( symbol ) != m_table.end();
}

boost::optional<Hack::word> SymbolTable::getAddress( const std::string& symbol ) const
{
    const auto it = m_table.find( symbol );

    return it != m_table.end() ? boost::make_optional( it->second ) : boost::none;
}

std::vector<std::string> SymbolTable::getSymbols() const
{
    std::vector<std::string> symbols;
    symbols.reserve( m_table.size() );

    for ( const auto& it : m_table )
    {
        symbols.emplace_back( it.first );
    }

    return symbols;

    //return boost::copy_range<std::vector<std::string>>( boost::adaptors::keys( m_table ) );
}

} // namespace Hasm
