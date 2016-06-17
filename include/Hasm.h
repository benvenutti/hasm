#ifndef HASM_HASM_H_
#define HASM_HASM_H_

namespace Hasm {
  enum class HasmCommandType {
      A_COMMAND,
      C_COMMAND,
      L_COMMAND,
      ERROR
  };

  const int INIT_RAM_ADDRESS = 16;
}

#endif
