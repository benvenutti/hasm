#ifndef HASM_CODER_H_
#define HASM_CODER_H_

#include <string>

#include "Hack.h"

namespace Hasm {
  class Coder {
    public:
      static Hack::WORD dest(const std::string& mnemonic);
      static Hack::WORD comp(const std::string& mnemonic);
      static Hack::WORD jump(const std::string& mnemonic);
  };
}

#endif
