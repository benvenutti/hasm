#include <hasm/AssemblerEngineConfig.hpp>

#include <catch2/catch_test_macros.hpp>

SCENARIO( "constructor", "[AssemblerEngineConfig]" )
{
    {
        const Hasm::AssemblerEngineConfig cfg( false, false, "input" );

        REQUIRE_FALSE( cfg.isValid() );
        REQUIRE_FALSE( cfg.exportSymbols() );
        REQUIRE( cfg.inputName() == std::string{ "input" } );
    }

    {
        const Hasm::AssemblerEngineConfig cfg( true, true, "file" );

        REQUIRE( cfg.isValid() );
        REQUIRE( cfg.exportSymbols() );
        REQUIRE( cfg.inputName() == std::string{ "file" } );
    }
}
