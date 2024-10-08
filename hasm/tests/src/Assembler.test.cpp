#include <hasm/Assembler.hpp>

#include <catch2/catch_test_macros.hpp>

#include <sstream>

namespace
{

struct FixtureAddProgram
{
    std::stringstream asmCode{ "@2 \n"
                               "D=A \n"
                               "@3 \n"
                               "D=D+A \n"
                               "@0 \n"
                               "M=D \n" };

    std::stringstream binCode{ "0000000000000010\n"
                               "1110110000010000\n"
                               "0000000000000011\n"
                               "1110000010010000\n"
                               "0000000000000000\n"
                               "1110001100001000\n" };
};

struct FixtureRectProgram
{
    std::stringstream asmCode{ "@0 \n"
                               "D=M \n"
                               "@INFINITE_LOOP \n"
                               "D;JLE \n"
                               "@counter \n"
                               "M=D \n"
                               "@SCREEN \n"
                               "D=A \n"
                               "@address \n"
                               "M=D \n"
                               "(LOOP) \n"
                               "@address \n"
                               "A=M \n"
                               "M=-1 \n"
                               "@address \n"
                               "D=M \n"
                               "@32 \n"
                               "D=D+A \n"
                               "@address \n"
                               "M=D \n"
                               "@counter \n"
                               "MD=M-1 \n"
                               "@LOOP \n"
                               "D;JGT \n"
                               "(INFINITE_LOOP) \n"
                               "@INFINITE_LOOP \n"
                               "0;JMP \n" };

    std::stringstream binCode{ "0000000000000000\n"
                               "1111110000010000\n"
                               "0000000000010111\n"
                               "1110001100000110\n"
                               "0000000000010000\n"
                               "1110001100001000\n"
                               "0100000000000000\n"
                               "1110110000010000\n"
                               "0000000000010001\n"
                               "1110001100001000\n"
                               "0000000000010001\n"
                               "1111110000100000\n"
                               "1110111010001000\n"
                               "0000000000010001\n"
                               "1111110000010000\n"
                               "0000000000100000\n"
                               "1110000010010000\n"
                               "0000000000010001\n"
                               "1110001100001000\n"
                               "0000000000010000\n"
                               "1111110010011000\n"
                               "0000000000001010\n"
                               "1110001100000001\n"
                               "0000000000010111\n"
                               "1110101010000111\n" };
};

const Hasm::Assembler::Logger logger = []( const auto& ) {};

} // namespace

SCENARIO_METHOD( FixtureAddProgram, "assemble program without labels", "[Assembler]" )
{
    std::stringstream binResult;

    Hasm::Assembler assembler{ asmCode, binResult, logger };
    assembler.assemble();

    REQUIRE( binResult.str() == binCode.str() );
}

SCENARIO_METHOD( FixtureRectProgram, "assemble program with labels", "[Assembler]" )
{
    std::stringstream binResult;

    Hasm::Assembler assembler{ asmCode, binResult, logger };
    assembler.assemble();

    REQUIRE( binResult.str() == binCode.str() );

    const auto& symbolTable = assembler.getSymbolTable();

    REQUIRE( symbolTable.contains( "counter" ) );
    REQUIRE( symbolTable.getAddress( "counter" ).value() == 16 );
    REQUIRE( symbolTable.contains( "address" ) );
    REQUIRE( symbolTable.getAddress( "address" ).value() == 17 );
    REQUIRE( symbolTable.contains( "LOOP" ) );
    REQUIRE( symbolTable.getAddress( "LOOP" ).value() == 10 );
    REQUIRE( symbolTable.contains( "INFINITE_LOOP" ) );
    REQUIRE( symbolTable.getAddress( "INFINITE_LOOP" ).value() == 23 );
}
