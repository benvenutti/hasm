#include <hasm/InstructionParser.hpp>

#include <catch2/catch_test_macros.hpp>

SCENARIO( "parse valid loads", "[InstructionParser]" )
{
    REQUIRE( Hasm::InstructionParser::isLoadCommand( "@10" ) );
    REQUIRE( Hasm::InstructionParser::isLoadCommand( "@1010" ) );
    REQUIRE( Hasm::InstructionParser::isLoadCommand( "@symbol" ) );
    REQUIRE( Hasm::InstructionParser::isLoadCommand( "@A" ) );
}

SCENARIO( "parse invalid loads", "[InstructionParser]" )
{
    REQUIRE_FALSE( Hasm::InstructionParser::isLoadCommand( "@symbol+" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLoadCommand( "@+symbol" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLoadCommand( "@symbol-" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLoadCommand( "@-symbol" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLoadCommand( "@+1" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLoadCommand( "@-1" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLoadCommand( "10" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLoadCommand( "id" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLoadCommand( "@" ) );
}
