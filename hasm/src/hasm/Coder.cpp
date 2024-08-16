#include <hasm/Coder.hpp>

#include <algorithm>

namespace Hasm
{

Hack::word Coder::dest( const std::string& mnemonic )
{
    Hack::word dest{ 0 };

    if ( mnemonic.find( 'M' ) != std::string::npos )
        dest |= 0b001;
    if ( mnemonic.find( 'D' ) != std::string::npos )
        dest |= 0b010;
    if ( mnemonic.find( 'A' ) != std::string::npos )
        dest |= 0b100;

    return static_cast<Hack::word>( dest << 3 );
}

Hack::word Coder::comp( const std::string& mnemonic )
{
    std::string m{ mnemonic };
    Hack::word  mask{ 0 };

    if ( m.find( 'M' ) != std::string::npos )
    {
        mask = 64; // 0b1000000
        std::replace( m.begin(), m.end(), 'M', 'A' );
    }

    Hack::word comp;

    if ( m == "0" )
        comp = 0b101010;
    else if ( m == "1" )
        comp = 0b111111;
    else if ( m == "-1" )
        comp = 0b111010;
    else if ( m == "D" )
        comp = 0b001100;
    else if ( m == "A" )
        comp = 0b110000;
    else if ( m == "!D" )
        comp = 0b001101;
    else if ( m == "!A" )
        comp = 0b110001;
    else if ( m == "-D" )
        comp = 0b001111;
    else if ( m == "-A" )
        comp = 0b110011;
    else if ( m == "D+1" )
        comp = 0b011111;
    else if ( m == "A+1" )
        comp = 0b110111;
    else if ( m == "D-1" )
        comp = 0b001110;
    else if ( m == "A-1" )
        comp = 0b110010;
    else if ( m == "D+A" )
        comp = 0b000010;
    else if ( m == "A+D" )
        comp = 0b000010;
    else if ( m == "D-A" )
        comp = 0b010011;
    else if ( m == "A-D" )
        comp = 0b000111;
    else if ( m == "D&A" )
        comp = 0b000000;
    else
        comp = 0b010101;

    comp |= mask;

    return static_cast<Hack::word>( comp << 6 );
}

Hack::word Coder::jump( const std::string& mnemonic )
{
    if ( mnemonic == "JGT" )
        return 0b001;
    if ( mnemonic == "JEQ" )
        return 0b010;
    if ( mnemonic == "JGE" )
        return 0b011;
    if ( mnemonic == "JLT" )
        return 0b100;
    if ( mnemonic == "JNE" )
        return 0b101;
    if ( mnemonic == "JLE" )
        return 0b110;
    if ( mnemonic == "JMP" )
        return 0b111;

    return static_cast<Hack::word>( 0 );
}

} // namespace Hasm
