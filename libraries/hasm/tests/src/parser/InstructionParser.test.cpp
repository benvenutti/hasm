#include <hasm/parser/InstructionParser.hpp>

#include <catch2/catch_test_macros.hpp>

#include <variant>

TEST_CASE( "InstructionParser::parse parses label declarations" )
{
    const auto result = Hasm::Parser::parse( "(LOOP)" );

    REQUIRE( result );
    REQUIRE( std::holds_alternative< Hasm::Model::Label >( *result ) );

    const auto& label = std::get< Hasm::Model::Label >( *result );

    REQUIRE( label.symbol.name == "LOOP" );
}

TEST_CASE( "InstructionParser::parse parses label declarations with valid symbols" )
{
    const auto result = Hasm::Parser::parse( "(_foo.bar$1:)" );

    REQUIRE( result );
    REQUIRE( std::holds_alternative< Hasm::Model::Label >( *result ) );

    const auto& label = std::get< Hasm::Model::Label >( *result );

    REQUIRE( label.symbol.name == "_foo.bar$1:" );
}

TEST_CASE( "InstructionParser::parse rejects invalid label declarations" )
{
    REQUIRE_FALSE( Hasm::Parser::parse( "()" ) );
    REQUIRE_FALSE( Hasm::Parser::parse( "(A" ) );
    REQUIRE_FALSE( Hasm::Parser::parse( "A)" ) );
    REQUIRE_FALSE( Hasm::Parser::parse( "(" ) );
    REQUIRE_FALSE( Hasm::Parser::parse( ")" ) );
    REQUIRE_FALSE( Hasm::Parser::parse( "(1)" ) );
    REQUIRE_FALSE( Hasm::Parser::parse( "(+)" ) );
    REQUIRE_FALSE( Hasm::Parser::parse( "(A+" ) );
}

TEST_CASE( "InstructionParser::parse parses A-instructions with literal operands" )
{
    const auto result = Hasm::Parser::parse( "@123" );

    REQUIRE( result );
    REQUIRE( std::holds_alternative< Hasm::Model::AddressInstruction >( *result ) );

    const auto& instruction = std::get< Hasm::Model::AddressInstruction >( *result );

    REQUIRE( std::holds_alternative< Hasm::Model::Literal >( instruction.operand ) );

    const auto& literal = std::get< Hasm::Model::Literal >( instruction.operand );

    REQUIRE( literal.value == 123 );
}

TEST_CASE( "InstructionParser::parse parses A-instructions with symbol operands" )
{
    const auto result = Hasm::Parser::parse( "@LOOP" );

    REQUIRE( result );
    REQUIRE( std::holds_alternative< Hasm::Model::AddressInstruction >( *result ) );

    const auto& instruction = std::get< Hasm::Model::AddressInstruction >( *result );

    REQUIRE( std::holds_alternative< Hasm::Model::Symbol >( instruction.operand ) );

    const auto& symbol = std::get< Hasm::Model::Symbol >( instruction.operand );

    REQUIRE( symbol.name == "LOOP" );
}

TEST_CASE( "InstructionParser::parse rejects invalid A-instructions" )
{
    REQUIRE_FALSE( Hasm::Parser::parse( "@" ) );
    REQUIRE_FALSE( Hasm::Parser::parse( "@+1" ) );
    REQUIRE_FALSE( Hasm::Parser::parse( "@-1" ) );
    REQUIRE_FALSE( Hasm::Parser::parse( "@+symbol" ) );
    REQUIRE_FALSE( Hasm::Parser::parse( "@symbol+" ) );
}
