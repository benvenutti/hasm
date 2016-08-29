#ifndef HASM_HACKLEX_H
#define HASM_HACKLEX_H

#include <string>

namespace Hack {
  namespace Lex {
    const std::string DEST_A{"A"};
    const std::string DEST_M{"M"};
    const std::string DEST_D{"D"};

    const std::string JUMP_JGT{"JGT"};
    const std::string JUMP_JGE{"JGE"};
    const std::string JUMP_JLT{"JLT"};
    const std::string JUMP_JLE{"JLE"};
    const std::string JUMP_JEQ{"JEQ"};
    const std::string JUMP_JNE{"JNE"};
    const std::string JUMP_JMP{"JMP"};
  }
}

#endif