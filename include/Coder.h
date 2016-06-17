#ifndef HASM_CODER_H_
#define HASM_CODER_H_

#include <string>

namespace Hasm {
  class Coder {
    public:
      unsigned int dest(const std::string& mnemonic) const;
      unsigned int comp(const std::string& mnemonic) const;
      unsigned int jump(const std::string& mnemonic) const;
  };
}

#endif
