#include <hasm/FileHandler.hpp>

#include <catch2/catch_test_macros.hpp>

SCENARIO( "change extension", "[FileHandler]" )
{
    const std::string file{ "file.asm" };

    REQUIRE( Hasm::FileHandler::changeExtension( file, ".hack" ) == std::string{ "file.hack" } );
    REQUIRE( Hasm::FileHandler::changeExtension( file, ".Hack" ) == std::string{ "file.Hack" } );
    REQUIRE( Hasm::FileHandler::changeExtension( file, ".HACK" ) == std::string{ "file.HACK" } );
}
