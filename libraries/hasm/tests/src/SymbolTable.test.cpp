#include <hasm/SymbolTable.hpp>

#include <catch2/catch_test_macros.hpp>

#include <ranges>

namespace
{

[[nodiscard]] Hasm::SymbolTable createSymbolTable()
{
    Hasm::SymbolTable table;

    table.addEntry( "s1", 0x1010 );
    table.addEntry( "s2", 0x2020 );
    table.addEntry( "s3", 0x3030 );

    return table;
}

} // namespace

TEST_CASE( "SymbolTable is empty by default" )
{
    const Hasm::SymbolTable table;

    REQUIRE( table.size() == 0 );
    REQUIRE_FALSE( table.contains( "s1" ) );
    REQUIRE( table.getAddress( "s1" ) == std::nullopt );
}

TEST_CASE( "SymbolTable::addEntry inserts symbols" )
{
    Hasm::SymbolTable table;

    table.addEntry( "s1", 0x1010 );

    REQUIRE( table.size() == 1 );
    REQUIRE( table.contains( "s1" ) );
    REQUIRE( table.getAddress( "s1" ) == 0x1010 );
}

TEST_CASE( "SymbolTable::contains reports whether a symbol exists" )
{
    const auto table = createSymbolTable();

    REQUIRE( table.contains( "s1" ) );
    REQUIRE( table.contains( "s2" ) );
    REQUIRE( table.contains( "s3" ) );
    REQUIRE_FALSE( table.contains( "s4" ) );
}

TEST_CASE( "SymbolTable::getAddress returns the address of a symbol" )
{
    const auto table = createSymbolTable();

    REQUIRE( table.getAddress( "s1" ) == 0x1010 );
    REQUIRE( table.getAddress( "s2" ) == 0x2020 );
    REQUIRE( table.getAddress( "s3" ) == 0x3030 );
}

TEST_CASE( "SymbolTable::getAddress returns std::nullopt when a symbol is absent" )
{
    const auto table = createSymbolTable();

    REQUIRE( table.getAddress( "s4" ) == std::nullopt );
}

TEST_CASE( "SymbolTable can be constructed from a map" )
{
    const Hasm::SymbolTable table{ {
        { "a", 0x7010_w },
        { "b", 0x8020_w },
    } };

    REQUIRE( table.size() == 2 );
    REQUIRE( table.getAddress( "a" ) == 0x7010 );
    REQUIRE( table.getAddress( "b" ) == 0x8020 );
    REQUIRE_FALSE( table.contains( "c" ) );
}

TEST_CASE( "SymbolTable supports iteration" )
{
    const auto table = createSymbolTable();

    REQUIRE( static_cast< size_t >( std::ranges::distance( table ) ) == table.size() );

    for ( const auto& symbol : table | std::views::keys )
    {
        REQUIRE_FALSE( symbol.empty() );
    }
}
