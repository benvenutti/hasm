#include <hasm/SymbolTableWriter.hpp>

#include <hasm/SymbolTable.hpp>

#include <format>

namespace Hasm
{

SymbolTableWriter::SymbolTableWriter( const SymbolTable& symbolTable )
{
    for ( const auto& [symbol, address] : symbolTable )
    {
        m_symbolMap.emplace( address, symbol );
    }
}

void SymbolTableWriter::write( std::ostream& out )
{
    for ( const auto& [address, symbol] : m_symbolMap )
    {
        out << std::format( "{:#06x} {}\n", address, symbol );
    }

    out.flush();
}

} // namespace Hasm
