#include <hasm/SymbolTableWriter.hpp>

#include <hasm/SymbolTable.hpp>

#include <boost/io/ios_state.hpp>

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
    boost::io::ios_flags_saver ifs{ out };

    for ( const auto& it : m_symbolMap )
    {
        out << "0x" << std::setfill( '0' ) << std::setw( 4 ) << std::hex << it.first << " " << it.second << '\n';
    }

    out.flush();
    ifs.restore();
}

} // namespace Hasm
