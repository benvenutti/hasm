#ifndef HASM_HASM_H_
#define HASM_HASM_H_

#include <limits>

#include "Hack.h"

namespace Hasm {
  enum class CommandType {
      A_COMMAND,
      C_COMMAND,
      L_COMMAND,
      INVALID
  };

  // max value for unsigned 15 bit number
  const Hack::WORD MAX_LOADABLE_VALUE = std::numeric_limits<Hack::WORD>::max() >> 1;
}

#endif
