#include "HackCommandParser.hpp"

#include <catch2/catch.hpp>

SCENARIO( "parse valid labels", "[HackCommandParser]" )
{
    REQUIRE( Hasm::HackCommandParser::isLabelCommand( "(A)" ) );
    REQUIRE( Hasm::HackCommandParser::isLabelCommand( "(AA)" ) );
    REQUIRE( Hasm::HackCommandParser::isLabelCommand( "(_)" ) );
    REQUIRE( Hasm::HackCommandParser::isLabelCommand( "(_A)" ) );
    REQUIRE( Hasm::HackCommandParser::isLabelCommand( "(_AA)" ) );
    REQUIRE( Hasm::HackCommandParser::isLabelCommand( "(.)" ) );
    REQUIRE( Hasm::HackCommandParser::isLabelCommand( "(.A)" ) );
    REQUIRE( Hasm::HackCommandParser::isLabelCommand( "(.AA)" ) )  ;
    REQUIRE( Hasm::HackCommandParser::isLabelCommand( "($)" ) );
    REQUIRE( Hasm::HackCommandParser::isLabelCommand( "($A)" ) );
    REQUIRE( Hasm::HackCommandParser::isLabelCommand( "($AA)" ) );
    REQUIRE( Hasm::HackCommandParser::isLabelCommand( "(:)" ) );
    REQUIRE( Hasm::HackCommandParser::isLabelCommand( "(:A)" ) );
    REQUIRE( Hasm::HackCommandParser::isLabelCommand( "(:AA)" ) );
}

SCENARIO( "parse invalid labels", "[HackCommandParser]" )
{
    REQUIRE_FALSE( Hasm::HackCommandParser::isLabelCommand( "()" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isLabelCommand( "(A" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isLabelCommand( "(AA" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isLabelCommand( "A)" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isLabelCommand( "AA)" ) );
}
