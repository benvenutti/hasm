#include <hasm/Coder.hpp>

#include <catch2/catch_test_macros.hpp>

SCENARIO( "single destination", "[Coder]" )
{
    REQUIRE( Hasm::Coder::dest( "M" ) == 0b001000u );
    REQUIRE( Hasm::Coder::dest( "D" ) == 0b010000u );
    REQUIRE( Hasm::Coder::dest( "A" ) == 0b100000u );
}

SCENARIO( "multi destination", "[Coder]" )
{
    REQUIRE( Hasm::Coder::dest( "MD" ) == 0b011000u );
    REQUIRE( Hasm::Coder::dest( "DM" ) == 0b011000u );
    REQUIRE( Hasm::Coder::dest( "AD" ) == 0b110000u );
    REQUIRE( Hasm::Coder::dest( "DA" ) == 0b110000u );
    REQUIRE( Hasm::Coder::dest( "AM" ) == 0b101000u );
    REQUIRE( Hasm::Coder::dest( "MA" ) == 0b101000u );
    REQUIRE( Hasm::Coder::dest( "AMD" ) == 0b111000u );
    REQUIRE( Hasm::Coder::dest( "ADM" ) == 0b111000u );
    REQUIRE( Hasm::Coder::dest( "DAM" ) == 0b111000u );
    REQUIRE( Hasm::Coder::dest( "DMA" ) == 0b111000u );
    REQUIRE( Hasm::Coder::dest( "MAD" ) == 0b111000u );
    REQUIRE( Hasm::Coder::dest( "MDA" ) == 0b111000u );
}

SCENARIO( "jumps", "[Coder]" )
{
    REQUIRE( Hasm::Coder::jump( "JGT" ) == 0b001u );
    REQUIRE( Hasm::Coder::jump( "JEQ" ) == 0b010u );
    REQUIRE( Hasm::Coder::jump( "JGE" ) == 0b011u );
    REQUIRE( Hasm::Coder::jump( "JLT" ) == 0b100u );
    REQUIRE( Hasm::Coder::jump( "JNE" ) == 0b101u );
    REQUIRE( Hasm::Coder::jump( "JLE" ) == 0b110u );
    REQUIRE( Hasm::Coder::jump( "JMP" ) == 0b111u );
}

SCENARIO( "computations", "[Coder]" )
{
    REQUIRE( Hasm::Coder::comp( "0" ) == 0b0101010000000u );
    REQUIRE( Hasm::Coder::comp( "1" ) == 0b0111111000000u );
    REQUIRE( Hasm::Coder::comp( "-1" ) == 0b0111010000000u );
    REQUIRE( Hasm::Coder::comp( "D" ) == 0b0001100000000u );
    REQUIRE( Hasm::Coder::comp( "A" ) == 0b0110000000000u );
    REQUIRE( Hasm::Coder::comp( "M" ) == 0b1110000000000u );
    REQUIRE( Hasm::Coder::comp( "!D" ) == 0b0001101000000u );
    REQUIRE( Hasm::Coder::comp( "!A" ) == 0b0110001000000u );
    REQUIRE( Hasm::Coder::comp( "!M" ) == 0b1110001000000u );
    REQUIRE( Hasm::Coder::comp( "-D" ) == 0b0001111000000u );
    REQUIRE( Hasm::Coder::comp( "-A" ) == 0b0110011000000u );
    REQUIRE( Hasm::Coder::comp( "-M" ) == 0b1110011000000u );
    REQUIRE( Hasm::Coder::comp( "D+1" ) == 0b0011111000000u );
    REQUIRE( Hasm::Coder::comp( "A+1" ) == 0b0110111000000u );
    REQUIRE( Hasm::Coder::comp( "M+1" ) == 0b1110111000000u );
    REQUIRE( Hasm::Coder::comp( "D-1" ) == 0b0001110000000u );
    REQUIRE( Hasm::Coder::comp( "A-1" ) == 0b0110010000000u );
    REQUIRE( Hasm::Coder::comp( "M-1" ) == 0b1110010000000u );
    REQUIRE( Hasm::Coder::comp( "D+A" ) == 0b0000010000000u );
    REQUIRE( Hasm::Coder::comp( "D+M" ) == 0b1000010000000u );
    REQUIRE( Hasm::Coder::comp( "A+D" ) == 0b0000010000000u );
    REQUIRE( Hasm::Coder::comp( "M+D" ) == 0b1000010000000u );
    REQUIRE( Hasm::Coder::comp( "D-A" ) == 0b0010011000000u );
    REQUIRE( Hasm::Coder::comp( "D-M" ) == 0b1010011000000u );
    REQUIRE( Hasm::Coder::comp( "A-D" ) == 0b0000111000000u );
    REQUIRE( Hasm::Coder::comp( "M-D" ) == 0b1000111000000u );
    REQUIRE( Hasm::Coder::comp( "D&A" ) == 0b0000000000000u );
    REQUIRE( Hasm::Coder::comp( "D&M" ) == 0b1000000000000u );
    REQUIRE( Hasm::Coder::comp( "D|A" ) == 0b0010101000000u );
    REQUIRE( Hasm::Coder::comp( "D|M" ) == 0b1010101000000u );
}
