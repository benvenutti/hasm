#pragma once

#include "Hack.hpp"

#include <limits>

namespace Hasm
{

enum class CommandType
{
    addressing,  /// A-Command
    computation, /// C-Command
    label,       /// L-Command
    invalid
};

// max value for unsigned 15 bit number
const Hack::WORD max_loadable_value = std::numeric_limits<Hack::WORD>::max() >> 1;

} // namespace Hasm
