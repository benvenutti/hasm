#include <hasm/AssemblerOptions.hpp>

#include <catch2/catch_test_macros.hpp>

SCENARIO( "constructor", "[AssemblerEngineConfig]" )
{
    {
        const Hasm::AssemblerOptions options( "file", false );

        REQUIRE_FALSE( options.exportSymbols() );
        REQUIRE( options.inputFile() == std::filesystem::path{ "file" } );
    }

    {
        const Hasm::AssemblerOptions options( "file", true );

        REQUIRE( options.exportSymbols() );
        REQUIRE( options.inputFile() == std::filesystem::path{ "file" } );
    }
}
