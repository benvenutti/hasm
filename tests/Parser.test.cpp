#include "Parser.hpp"

#include <catch2/catch.hpp>

#include <boost/range/irange.hpp>

#include <sstream>

namespace
{

struct Fixture
{
    std::stringstream asmProgram{ "@30 \n"
                                  "D=A \n"
                                  "@1010 \n"
                                  "M=D+1 \n"
                                  "AMD=!A;JGT \n"
                                  "(LABEL_LOOP) \n"
                                  "// line comment \n"
                                  "@LABEL_LOOP \n"
                                  "0;JMP \n" };
};

} // anonymous namespace

SCENARIO_METHOD( Fixture, "commands", "[parser]" )
{
    Hasm::Parser parser{ asmProgram };

    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommand() == "@30" );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommand() == "D=A" );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommand() == "@1010" );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommand() == "M=D+1" );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommand() == "AMD=!A;JGT" );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommand() == "(LABEL_LOOP)" );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommand() == "@LABEL_LOOP" );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommand() == "0;JMP" );
}

SCENARIO_METHOD( Fixture, "commands types", "[parser]" )
{
    Hasm::Parser parser{ asmProgram };

    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommandType() == Hasm::CommandType::addressing );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommandType() == Hasm::CommandType::computation );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommandType() == Hasm::CommandType::addressing );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommandType() == Hasm::CommandType::computation );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommandType() == Hasm::CommandType::computation );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommandType() == Hasm::CommandType::label );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommandType() == Hasm::CommandType::addressing );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommandType() == Hasm::CommandType::computation );
}

SCENARIO_METHOD( Fixture, "line number", "[parser]" )
{
    Hasm::Parser parser{ asmProgram };

    REQUIRE( parser.advance() );
    REQUIRE( parser.getCurrentLineNumber() == 1 );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCurrentLineNumber() == 2 );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCurrentLineNumber() == 3 );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCurrentLineNumber() == 4 );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCurrentLineNumber() == 5 );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCurrentLineNumber() == 6 );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCurrentLineNumber() == 8 );
    REQUIRE( parser.advance() );
    REQUIRE( parser.getCurrentLineNumber() == 9 );
}

SCENARIO_METHOD( Fixture, "reset", "[parser]" )
{
    Hasm::Parser parser{ asmProgram };

    for ( auto i : boost::irange( 0, 2 ) )
    {
        REQUIRE( parser.advance() );
        REQUIRE( parser.getCommand() == "@30" );
        REQUIRE( parser.advance() );
        REQUIRE( parser.getCommand() == "D=A" );
        REQUIRE( parser.advance() );
        REQUIRE( parser.getCommand() == "@1010" );
        REQUIRE( parser.advance() );
        REQUIRE( parser.getCommand() == "M=D+1" );
        REQUIRE( parser.advance() );
        REQUIRE( parser.getCommand() == "AMD=!A;JGT" );
        REQUIRE( parser.advance() );
        REQUIRE( parser.getCommand() == "(LABEL_LOOP)" );
        REQUIRE( parser.advance() );
        REQUIRE( parser.getCommand() == "@LABEL_LOOP" );
        REQUIRE( parser.advance() );
        REQUIRE( parser.getCommand() == "0;JMP" );
        parser.reset();
    }
}

SCENARIO_METHOD( Fixture, "command full info", "[parser]" )
{
    Hasm::Parser parser{ asmProgram };

    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommand() == "@30" );
    REQUIRE( parser.symbol() == "30" );

    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommand() == "D=A" );
    REQUIRE( parser.dest() == "D" );
    REQUIRE( parser.comp() == "A" );
    REQUIRE( parser.jump() == "" );

    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommand() == "@1010" );
    REQUIRE( parser.symbol() == "1010" );

    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommand() == "M=D+1" );
    REQUIRE( parser.dest() == "M" );
    REQUIRE( parser.comp() == "D+1" );
    REQUIRE( parser.jump() == "" );

    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommand() == "AMD=!A;JGT" );
    REQUIRE( parser.dest() == "AMD" );
    REQUIRE( parser.comp() == "!A" );
    REQUIRE( parser.jump() == "JGT" );

    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommand() == "(LABEL_LOOP)" );
    REQUIRE( parser.symbol() == "LABEL_LOOP" );

    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommand() == "@LABEL_LOOP" );
    REQUIRE( parser.symbol() == "LABEL_LOOP" );

    REQUIRE( parser.advance() );
    REQUIRE( parser.getCommand() == "0;JMP" );
    REQUIRE( parser.dest() == "" );
    REQUIRE( parser.comp() == "0" );
    REQUIRE( parser.jump() == "JMP" );
}

SCENARIO_METHOD( Fixture, "status", "[parser]" )
{
    {
        std::stringstream ss{ "" };
        Hasm::Parser      parser{ ss };
        REQUIRE( parser.getStatus() == Hasm::Parser::Status::start_of_file );
    }

    {
        std::stringstream ss{ "@1" };
        Hasm::Parser      parser{ ss };
        REQUIRE( parser.advance() );
        REQUIRE( parser.getStatus() == Hasm::Parser::Status::valid_command );
    }

    {
        std::stringstream ss{ "+a" };
        Hasm::Parser      parser{ ss };
        REQUIRE_FALSE( parser.advance() );
        REQUIRE( parser.getStatus() == Hasm::Parser::Status::invalid_command );
    }

    {
        std::stringstream ss{ "" };
        Hasm::Parser      parser{ ss };
        REQUIRE_FALSE( parser.advance() );
        REQUIRE( parser.getStatus() == Hasm::Parser::Status::end_of_file );
    }
}
