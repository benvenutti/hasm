#include "FileHandler.hpp"

#include <catch2/catch.hpp>

SCENARIO( "change extension", "[FileHandler]" )
{
    const std::string file{ "file.asm" };

    REQUIRE( Hasm::FileHandler::changeExtension( file, ".hack" ) == std::string{ "file.hack" } );
    REQUIRE( Hasm::FileHandler::changeExtension( file, ".Hack" ) == std::string{ "file.Hack" } );
    REQUIRE( Hasm::FileHandler::changeExtension( file, ".HACK" ) == std::string{ "file.HACK" } );
}

SCENARIO( "has extension", "[FileHandler]" )
{
    const std::string file{ "file.asm" };

    REQUIRE( Hasm::FileHandler::hasExtension( file, ".asm" ) );
    REQUIRE( Hasm::FileHandler::hasExtension( file, ".aSm" ) );
    REQUIRE( Hasm::FileHandler::hasExtension( file, ".ASM" ) );
    REQUIRE_FALSE( Hasm::FileHandler::hasExtension( file, "asm" ) );
    REQUIRE_FALSE( Hasm::FileHandler::hasExtension( file, "aSm" ) );
    REQUIRE_FALSE( Hasm::FileHandler::hasExtension( file, "ASM" ) );
}
