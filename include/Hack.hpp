#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>

namespace Hasm
{
namespace Hack
{

using WORD = uint16_t;

const WORD init_ram_address{ 16 };

const std::unordered_map<std::string, WORD> predefined_symbols{
    { "SP", 0x0 },  { "LCL", 0x1 }, { "ARG", 0x2 }, { "THIS", 0x3 },      { "THAT", 0x4 },  { "R0", 0x0 },
    { "R1", 0x1 },  { "R2", 0x2 },  { "R3", 0x3 },  { "R4", 0x4 },        { "R5", 0x5 },    { "R6", 0x6 },
    { "R7", 0x7 },  { "R8", 0x8 },  { "R9", 0x9 },  { "R10", 0xA },       { "R11", 0xB },   { "R12", 0xC },
    { "R13", 0xD }, { "R14", 0xE }, { "R15", 0xF }, { "SCREEN", 0x4000 }, { "KBD", 0x6000 }
};

} // namespace Hack
} // namespace Hasm
