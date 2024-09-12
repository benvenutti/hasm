#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>

constexpr uint16_t operator"" _w( unsigned long long value )
{
    return static_cast< uint16_t >( value );
}

namespace Hasm
{
namespace Hack
{

using word = uint16_t;

constexpr word init_ram_address{ 16_w };

const std::unordered_map< std::string, word > predefined_symbols{
    { "SP", 0x0_w },  { "LCL", 0x1_w }, { "ARG", 0x2_w }, { "THIS", 0x3_w },      { "THAT", 0x4_w },  { "R0", 0x0_w },
    { "R1", 0x1_w },  { "R2", 0x2_w },  { "R3", 0x3_w },  { "R4", 0x4_w },        { "R5", 0x5_w },    { "R6", 0x6_w },
    { "R7", 0x7_w },  { "R8", 0x8_w },  { "R9", 0x9_w },  { "R10", 0xA_w },       { "R11", 0xB_w },   { "R12", 0xC_w },
    { "R13", 0xD_w }, { "R14", 0xE_w }, { "R15", 0xF_w }, { "SCREEN", 0x4000_w }, { "KBD", 0x6000_w }
};

} // namespace Hack
} // namespace Hasm
