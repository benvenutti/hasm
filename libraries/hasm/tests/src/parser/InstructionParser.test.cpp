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

TEST_CASE( "InstructionParser::parse parses C-instructions without destination or jump" )
{
    const auto result = Hasm::Parser::parse( "D" );

    REQUIRE( result );
    REQUIRE( std::holds_alternative< Hasm::Model::ComputeInstruction >( *result ) );

    const auto& instruction = std::get< Hasm::Model::ComputeInstruction >( *result );

    REQUIRE_FALSE( instruction.dest );
    REQUIRE( instruction.comp == Hasm::Model::Comp::D );
    REQUIRE_FALSE( instruction.jump );
}

TEST_CASE( "InstructionParser::parse parses C-instructions with a destination" )
{
    const auto result = Hasm::Parser::parse( "AD=D+1" );

    REQUIRE( result );
    REQUIRE( std::holds_alternative< Hasm::Model::ComputeInstruction >( *result ) );

    const auto& instruction = std::get< Hasm::Model::ComputeInstruction >( *result );

    REQUIRE( instruction.dest == Hasm::Model::Dest::AD );
    REQUIRE( instruction.comp == Hasm::Model::Comp::IncrementD );
    REQUIRE_FALSE( instruction.jump );
}

TEST_CASE( "InstructionParser::parse parses C-instructions with a jump" )
{
    const auto result = Hasm::Parser::parse( "D;JGT" );

    REQUIRE( result );
    REQUIRE( std::holds_alternative< Hasm::Model::ComputeInstruction >( *result ) );

    const auto& instruction = std::get< Hasm::Model::ComputeInstruction >( *result );

    REQUIRE_FALSE( instruction.dest );
    REQUIRE( instruction.comp == Hasm::Model::Comp::D );
    REQUIRE( instruction.jump == Hasm::Model::Jump::JGT );
}

TEST_CASE( "InstructionParser::parse parses complete C-instructions" )
{
    const auto result = Hasm::Parser::parse( "AMD=M-1;JNE" );

    REQUIRE( result );
    REQUIRE( std::holds_alternative< Hasm::Model::ComputeInstruction >( *result ) );

    const auto& instruction = std::get< Hasm::Model::ComputeInstruction >( *result );

    REQUIRE( instruction.dest == Hasm::Model::Dest::AMD );
    REQUIRE( instruction.comp == Hasm::Model::Comp::DecrementM );
    REQUIRE( instruction.jump == Hasm::Model::Jump::JNE );
}

TEST_CASE( "InstructionParser::parse rejects C-instructions with invalid destinations" )
{
    REQUIRE_FALSE( Hasm::Parser::parse( "DA=D" ) );
    REQUIRE_FALSE( Hasm::Parser::parse( "MA=M" ) );
    REQUIRE_FALSE( Hasm::Parser::parse( "DM=D" ) );
}

TEST_CASE( "InstructionParser::parse rejects C-instructions with invalid computations" )
{
    REQUIRE_FALSE( Hasm::Parser::parse( "=" ) );
    REQUIRE_FALSE( Hasm::Parser::parse( "D==" ) );
    REQUIRE_FALSE( Hasm::Parser::parse( "D=M+A" ) );
    REQUIRE_FALSE( Hasm::Parser::parse( "D=A+D" ) );
    REQUIRE_FALSE( Hasm::Parser::parse( "D=42" ) );
}

TEST_CASE( "InstructionParser::parse rejects C-instructions with invalid jumps" )
{
    REQUIRE_FALSE( Hasm::Parser::parse( "D;JXX" ) );
    REQUIRE_FALSE( Hasm::Parser::parse( "D;J" ) );
    REQUIRE_FALSE( Hasm::Parser::parse( "D;" ) );
}
