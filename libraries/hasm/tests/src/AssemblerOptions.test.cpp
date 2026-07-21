#include <hasm/AssemblerOptions.hpp>

#include <catch2/catch_test_macros.hpp>

SCENARIO( "constructor", "[AssemblerEngineConfig]" )
{
    {
        const Hasm::AssemblerOptions options( "in", "out", false );

        REQUIRE( options.inputFile() == std::filesystem::path{ "in" } );
        REQUIRE( options.outputFile() == std::filesystem::path{ "out" } );
        REQUIRE_FALSE( options.exportSymbols() );
    }

    {
        const Hasm::AssemblerOptions options( "in", "out", true );

        REQUIRE( options.inputFile() == std::filesystem::path{ "in" } );
        REQUIRE( options.outputFile() == std::filesystem::path{ "out" } );
        REQUIRE( options.exportSymbols() );
    }
}
