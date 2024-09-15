#include <hasm/InstructionParser.hpp>

#include <catch2/catch_test_macros.hpp>

SCENARIO( "parse valid labels", "[InstructionParser]" )
{
    REQUIRE( Hasm::InstructionParser::isLabelCommand( "(A)" ) );
    REQUIRE( Hasm::InstructionParser::isLabelCommand( "(AA)" ) );
    REQUIRE( Hasm::InstructionParser::isLabelCommand( "(_)" ) );
    REQUIRE( Hasm::InstructionParser::isLabelCommand( "(_A)" ) );
    REQUIRE( Hasm::InstructionParser::isLabelCommand( "(_AA)" ) );
    REQUIRE( Hasm::InstructionParser::isLabelCommand( "(.)" ) );
    REQUIRE( Hasm::InstructionParser::isLabelCommand( "(.A)" ) );
    REQUIRE( Hasm::InstructionParser::isLabelCommand( "(.AA)" ) );
    REQUIRE( Hasm::InstructionParser::isLabelCommand( "($)" ) );
    REQUIRE( Hasm::InstructionParser::isLabelCommand( "($A)" ) );
    REQUIRE( Hasm::InstructionParser::isLabelCommand( "($AA)" ) );
    REQUIRE( Hasm::InstructionParser::isLabelCommand( "(:)" ) );
    REQUIRE( Hasm::InstructionParser::isLabelCommand( "(:A)" ) );
    REQUIRE( Hasm::InstructionParser::isLabelCommand( "(:AA)" ) );
}

SCENARIO( "parse invalid labels", "[InstructionParser]" )
{
    REQUIRE_FALSE( Hasm::InstructionParser::isLabelCommand( "()" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLabelCommand( "(A" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLabelCommand( "(AA" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLabelCommand( "A)" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLabelCommand( "AA)" ) );
}
