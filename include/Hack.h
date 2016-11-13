#ifndef HACK_H
#define HACK_H

#include <cstdint>
#include <map>
#include <string>

namespace Hack {

using WORD = uint16_t;

const WORD INIT_RAM_ADDRESS{16};

const std::map<std::string, Hack::WORD> PREDEFINED_SYMBOLS{
    {"SP", 0x00},
    {"LCL", 0x01},
    {"ARG", 0x02},
    {"THIS", 0x03},
    {"THAT", 0x04},
    {"R0", 0x00},
    {"R1", 0x01},
    {"R2", 0x02},
    {"R3", 0x03},
    {"R4", 0x04},
    {"R5", 0x05},
    {"R6", 0x06},
    {"R7", 0x07},
    {"R8", 0x08},
    {"R9", 0x09},
    {"R10", 0x10},
    {"R11", 0x11},
    {"R12", 0x12},
    {"R13", 0x13},
    {"R14", 0x14},
    {"R15", 0x15},
    {"SCREEN", 0x4000},
    {"KBD", 0x6000}
};

} // namespace Hack

#endif