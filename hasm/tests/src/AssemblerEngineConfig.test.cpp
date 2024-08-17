#include <hasm/AssemblerEngineConfig.hpp>

#include <catch2/catch_test_macros.hpp>

SCENARIO( "constructor", "[AssemblerEngineConfig]" )
{
    {
        const Hasm::AssemblerEngineConfig cfg( false, "input" );

        REQUIRE_FALSE( cfg.exportSymbols() );
        REQUIRE( cfg.inputName() == std::string{ "input" } );
    }

    {
        const Hasm::AssemblerEngineConfig cfg( true, "file" );

        REQUIRE( cfg.exportSymbols() );
        REQUIRE( cfg.inputName() == std::string{ "file" } );
    }
}
