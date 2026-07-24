#include <hasm/SymbolListingWriter.hpp>

#include <algorithm>
#include <format>
#include <vector>

void Hasm::SymbolListingWriter::write( std::ostream& out, const SymbolTable& symbolTable )
{
    using Entry = std::pair< Hack::word, std::string >;

    std::vector< Entry > entries;

    entries.reserve( symbolTable.size() );

    for ( const auto& [symbol, address] : symbolTable )
    {
        entries.emplace_back( address, symbol );
    }

    std::ranges::sort( entries );

    for ( const auto& [address, symbol] : entries )
    {
        out << std::format( "{:#06x} {}\n", address, symbol );
    }
}
