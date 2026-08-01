#include <hasm/parser/InstructionMatcher.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE( "InstructionMatcher::matchesLabel accepts valid label declarations" )
{
    REQUIRE( Hasm::Parser::matchesLabel( "(A)" ) );
    REQUIRE( Hasm::Parser::matchesLabel( "(AA)" ) );
    REQUIRE( Hasm::Parser::matchesLabel( "(_)" ) );
    REQUIRE( Hasm::Parser::matchesLabel( "(_A)" ) );
    REQUIRE( Hasm::Parser::matchesLabel( "(_AA)" ) );
    REQUIRE( Hasm::Parser::matchesLabel( "(.)" ) );
    REQUIRE( Hasm::Parser::matchesLabel( "(.A)" ) );
    REQUIRE( Hasm::Parser::matchesLabel( "(.AA)" ) );
    REQUIRE( Hasm::Parser::matchesLabel( "($)" ) );
    REQUIRE( Hasm::Parser::matchesLabel( "($A)" ) );
    REQUIRE( Hasm::Parser::matchesLabel( "($AA)" ) );
    REQUIRE( Hasm::Parser::matchesLabel( "(:)" ) );
    REQUIRE( Hasm::Parser::matchesLabel( "(:A)" ) );
    REQUIRE( Hasm::Parser::matchesLabel( "(:AA)" ) );
}

TEST_CASE( "InstructionMatcher::matchesLabel rejects invalid label declarations" )
{
    REQUIRE_FALSE( Hasm::Parser::matchesLabel( "()" ) );
    REQUIRE_FALSE( Hasm::Parser::matchesLabel( "(A" ) );
    REQUIRE_FALSE( Hasm::Parser::matchesLabel( "(AA" ) );
    REQUIRE_FALSE( Hasm::Parser::matchesLabel( "A)" ) );
    REQUIRE_FALSE( Hasm::Parser::matchesLabel( "AA)" ) );
}

TEST_CASE( "InstructionMatcher::matchesAddressInstruction accepts valid A-instructions" )
{
    REQUIRE( Hasm::Parser::matchesAddressInstruction( "@10" ) );
    REQUIRE( Hasm::Parser::matchesAddressInstruction( "@1010" ) );
    REQUIRE( Hasm::Parser::matchesAddressInstruction( "@symbol" ) );
    REQUIRE( Hasm::Parser::matchesAddressInstruction( "@A" ) );
}

TEST_CASE( "InstructionMatcher::matchesAddressInstruction rejects invalid A-instructions" )
{
    REQUIRE_FALSE( Hasm::Parser::matchesAddressInstruction( "@symbol+" ) );
    REQUIRE_FALSE( Hasm::Parser::matchesAddressInstruction( "@+symbol" ) );
    REQUIRE_FALSE( Hasm::Parser::matchesAddressInstruction( "@symbol-" ) );
    REQUIRE_FALSE( Hasm::Parser::matchesAddressInstruction( "@-symbol" ) );
    REQUIRE_FALSE( Hasm::Parser::matchesAddressInstruction( "@+1" ) );
    REQUIRE_FALSE( Hasm::Parser::matchesAddressInstruction( "@-1" ) );
    REQUIRE_FALSE( Hasm::Parser::matchesAddressInstruction( "10" ) );
    REQUIRE_FALSE( Hasm::Parser::matchesAddressInstruction( "id" ) );
    REQUIRE_FALSE( Hasm::Parser::matchesAddressInstruction( "@" ) );
}

TEST_CASE( "InstructionMatcher classifies label declarations correctly" )
{
    REQUIRE( Hasm::Parser::matchesLabel( "(LOOP)" ) );
    REQUIRE_FALSE( Hasm::Parser::matchesAddressInstruction( "(LOOP)" ) );
}

TEST_CASE( "InstructionMatcher classifies A-instructions correctly" )
{
    REQUIRE( Hasm::Parser::matchesAddressInstruction( "@LOOP" ) );
    REQUIRE_FALSE( Hasm::Parser::matchesLabel( "@LOOP" ) );
}
