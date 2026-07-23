#include <hasm/SymbolListingWriter.hpp>

#include <hasm/SymbolTable.hpp>

#include <format>

namespace Hasm
{

SymbolListingWriter::SymbolListingWriter( const SymbolTable& symbolTable )
{
    for ( const auto& [symbol, address] : symbolTable )
    {
        m_symbolMap.emplace( address, symbol );
    }
}

void SymbolListingWriter::write( std::ostream& out )
{
    for ( const auto& [address, symbol] : m_symbolMap )
    {
        out << std::format( "{:#06x} {}\n", address, symbol );
    }

    out.flush();
}

} // namespace Hasm
