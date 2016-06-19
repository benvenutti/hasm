#ifndef HASM_CODER_H_
#define HASM_CODER_H_

#include <string>

namespace Hasm {
  class Coder {
    public:
      static unsigned int dest(const std::string& mnemonic);
      static unsigned int comp(const std::string& mnemonic);
      static unsigned int jump(const std::string& mnemonic);
  };
}

#endif
