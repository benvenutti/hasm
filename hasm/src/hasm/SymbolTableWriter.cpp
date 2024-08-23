#include <hasm/SymbolTableWriter.hpp>

#include <hasm/SymbolTable.hpp>

#include <iomanip>

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
    const std::ios_base::fmtflags flags( out.flags() );

    for ( const auto& [address, symbol] : m_symbolMap )
    {
        out << "0x" << std::setfill( '0' ) << std::setw( 4 ) << std::hex << address << " " << symbol << '\n';
    }

    out.flush();
    out.flags( flags );
}

} // namespace Hasm
