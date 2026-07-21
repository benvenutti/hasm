#include <hasm/AssemblerEngineConfig.hpp>

#include <catch2/catch_test_macros.hpp>

SCENARIO( "constructor", "[AssemblerEngineConfig]" )
{
    {
        const Hasm::AssemblerEngineConfig cfg( "file", false );

        REQUIRE_FALSE( cfg.exportSymbols() );
        REQUIRE( cfg.inputFile() == std::filesystem::path{ "file" } );
    }

    {
        const Hasm::AssemblerEngineConfig cfg( "file", true );

        REQUIRE( cfg.exportSymbols() );
        REQUIRE( cfg.inputFile() == std::filesystem::path{ "file" } );
    }
}
