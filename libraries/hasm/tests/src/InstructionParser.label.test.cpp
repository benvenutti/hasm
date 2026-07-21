#include <hasm/InstructionParser.hpp>

#include <catch2/catch_test_macros.hpp>

SCENARIO( "parse valid labels", "[InstructionParser]" )
{
    REQUIRE( Hasm::InstructionParser::isLabel( "(A)" ) );
    REQUIRE( Hasm::InstructionParser::isLabel( "(AA)" ) );
    REQUIRE( Hasm::InstructionParser::isLabel( "(_)" ) );
    REQUIRE( Hasm::InstructionParser::isLabel( "(_A)" ) );
    REQUIRE( Hasm::InstructionParser::isLabel( "(_AA)" ) );
    REQUIRE( Hasm::InstructionParser::isLabel( "(.)" ) );
    REQUIRE( Hasm::InstructionParser::isLabel( "(.A)" ) );
    REQUIRE( Hasm::InstructionParser::isLabel( "(.AA)" ) );
    REQUIRE( Hasm::InstructionParser::isLabel( "($)" ) );
    REQUIRE( Hasm::InstructionParser::isLabel( "($A)" ) );
    REQUIRE( Hasm::InstructionParser::isLabel( "($AA)" ) );
    REQUIRE( Hasm::InstructionParser::isLabel( "(:)" ) );
    REQUIRE( Hasm::InstructionParser::isLabel( "(:A)" ) );
    REQUIRE( Hasm::InstructionParser::isLabel( "(:AA)" ) );
}

SCENARIO( "parse invalid labels", "[InstructionParser]" )
{
    REQUIRE_FALSE( Hasm::InstructionParser::isLabel( "()" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLabel( "(A" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLabel( "(AA" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLabel( "A)" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLabel( "AA)" ) );
}
