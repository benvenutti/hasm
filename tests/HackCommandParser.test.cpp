#include "HackCommandParser.hpp"

#include <catch2/catch.hpp>

SCENARIO( "parse labels", "[HackCommandParser]" )
{
    REQUIRE( Hasm::HackCommandParser::isLabelCommand( "(_id)" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isLabelCommand( "(_id" ) );
}

SCENARIO( "parse computations", "[HackCommandParser]" )
{
    REQUIRE( Hasm::HackCommandParser::isComputationCommand( "D+1" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "D+X" ) );

    // destinations
    REQUIRE( Hasm::HackCommandParser::isComputationCommand( "D=D+A" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "X=D+A" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "1=D+A" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "=D+A" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "D=X" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "D=2" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "D=" ) );

    // valid computation and jump
    REQUIRE( Hasm::HackCommandParser::isComputationCommand( "D+A;JMP" ) );

    // invalid computation and valid jump
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "X;JMP" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "2;JGT" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( ";JGE" ) );

    // valid computation and invalid jump
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "D;JM" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "D;JG" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "D;" ) );

    // valid destination, computation and jump
    REQUIRE( Hasm::HackCommandParser::isComputationCommand( "D=D+1;JMP" ) );

    // invalid destination, valid computation and jump
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "d=D+1;JMP" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "0=D+1;JMP" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "=D+1;JMP" ) );

    // valid destination, invalid computation and valid jump
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "D=d+1;JMP" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "D=D+;JMP" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "D=;JMP" ) );

    // valid destination and computation, invalid jump
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "D=A+1;jmp" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "D=D+1;JM" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isComputationCommand( "D=M+1;" ) );
}

SCENARIO( "parse loads", "[HackCommandParser]" )
{
    REQUIRE( Hasm::HackCommandParser::isLoadCommand( "@10" ) );
    REQUIRE( Hasm::HackCommandParser::isLoadCommand( "@symbol" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isLoadCommand( "@" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isLoadCommand( "@+1" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isLoadCommand( "10" ) );
    REQUIRE_FALSE( Hasm::HackCommandParser::isLoadCommand( "id" ) );
}
