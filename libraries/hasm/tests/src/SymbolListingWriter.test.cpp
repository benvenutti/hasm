#include <hasm/SymbolListingWriter.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE( "SymbolListingWriter::write writes an empty symbol table" )
{
    const Hasm::SymbolTable symbolTable;

    std::stringstream out;
    Hasm::SymbolListingWriter::write( out, symbolTable );

    REQUIRE( out.str().empty() );
}

TEST_CASE( "SymbolListingWriter::write writes symbols ordered by address" )
{
    Hasm::SymbolTable symbolTable;
    symbolTable.addEntry( "z", 0x2010 );
    symbolTable.addEntry( "a", 0x1030 );
    symbolTable.addEntry( "m", 0x3020 );

    std::stringstream out;
    Hasm::SymbolListingWriter::write( out, symbolTable );

    REQUIRE( out.str()
             == "0x1030 a\n"
                "0x2010 z\n"
                "0x3020 m\n" );
}
