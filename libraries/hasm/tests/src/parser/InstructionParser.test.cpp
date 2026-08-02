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
