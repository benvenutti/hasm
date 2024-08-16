#include "HackCommandParser.hpp"

#include <catch2/catch_test_macros.hpp>

SCENARIO( "parse valid loads", "[HackCommandParser]" )
{
    REQUIRE( Hasm::HackCommandParser::isLoadCommand( "@10" ) );
    REQUIRE( Hasm::HackCommandParser::isLoadCommand( "@1010" ) );
    REQUIRE( Hasm::HackCommandParser::isLoadCommand( "@symbol" ) );
    REQUIRE( Hasm::HackCommandParser::isLoadCommand( "@A" ) );
}

SCENARIO( "parse invalid loads", "[HackCommandParser]" )
{
    REQUIRE_FALSE( Hasm::HackCommandParser::isLoadCommand( "@symbol+" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isLoadCommand( "@+symbol" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isLoadCommand( "@symbol-" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isLoadCommand( "@-symbol" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isLoadCommand( "@+1" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isLoadCommand( "@-1" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isLoadCommand( "10" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isLoadCommand( "id" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isLoadCommand( "@" ) );
}
