#pragma once

#include "Hack.hpp"

#include <limits>

namespace Hasm
{

enum class CommandType
{
    addressing,  /// A-Command
    computation, /// C-Command
    label        /// L-Command
};

// max value for unsigned 15 bit number
const Hack::word max_loadable_value = std::numeric_limits< Hack::word >::max() >> 1;

} // namespace Hasm
