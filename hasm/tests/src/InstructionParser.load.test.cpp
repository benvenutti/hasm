#include <hasm/InstructionParser.hpp>

#include <catch2/catch_test_macros.hpp>

SCENARIO( "parse valid loads", "[InstructionParser]" )
{
    REQUIRE( Hasm::InstructionParser::isLoad( "@10" ) );
    REQUIRE( Hasm::InstructionParser::isLoad( "@1010" ) );
    REQUIRE( Hasm::InstructionParser::isLoad( "@symbol" ) );
    REQUIRE( Hasm::InstructionParser::isLoad( "@A" ) );
}

SCENARIO( "parse invalid loads", "[InstructionParser]" )
{
    REQUIRE_FALSE( Hasm::InstructionParser::isLoad( "@symbol+" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLoad( "@+symbol" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLoad( "@symbol-" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLoad( "@-symbol" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLoad( "@+1" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLoad( "@-1" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLoad( "10" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLoad( "id" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isLoad( "@" ) );
}
