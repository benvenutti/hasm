#ifndef HASM_HASM_HPP
#define HASM_HASM_HPP

#include <limits>

#include "Hack.hpp"

namespace Hasm {

enum class CommandType {
    ADDRESSING,  /// A-Command
    COMPUTATION, /// C-Command
    LABEL,       /// L-Command
    INVALID
};

// max value for unsigned 15 bit number
const Hack::WORD MAX_LOADABLE_VALUE = std::numeric_limits<Hack::WORD>::max() >> 1;

} // namespace Hasm

#endif
