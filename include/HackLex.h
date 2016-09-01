#ifndef HASM_HACKLEX_H
#define HASM_HACKLEX_H

#include <string>

namespace Hack {
  namespace Lex {
    const std::string ID{"([[:alpha:]]|\\_|\\.|\\$|\\:)(\\w|\\.|\\$|\\:)*"};
    const std::string INTEGER{"\\d+"};

    const std::string SEMICOLON{"\\;"};
    const std::string EQUAL{"\\="};
    const std::string LEFT_PAREN{"\\("};
    const std::string RIGHT_PAREN{"\\)"};

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

    const std::string COMP_ZERO{"0"};
    const std::string COMP_ONE{"1"};
    const std::string COMP_MINUS_ONE{"\\-1"};
    const std::string COMP_D{"D"};
    const std::string COMP_A{"A"};
    const std::string COMP_NOT_D{"\\!D"};
    const std::string COMP_NOT_A{"\\!A"};
    const std::string COMP_MINUS_D{"\\-D"};
    const std::string COMP_MINUS_A{"\\-A"};
    const std::string COMP_D_PLUS_ONE{"D\\+1"};
    const std::string COMP_A_PLUS_ONE{"A\\+1"};
    const std::string COMP_D_MINUS_ONE{"D\\-1"};
    const std::string COMP_A_MINUS_ONE{"A\\-1"};
    const std::string COMP_D_PLUS_A{"D\\+A"};
    const std::string COMP_D_MINUS_A{"D\\-A"};
    const std::string COMP_A_MINUS_D{"A\\-D"};
    const std::string COMP_D_AND_A{"D\\&A"};
    const std::string COMP_D_OR_A{"D\\|A"};
    const std::string COMP_M{"M"};
    const std::string COMP_NOT_M{"\\!M"};
    const std::string COMP_MINUS_M{"\\-M"};
    const std::string COMP_M_PLUS_ONE{"M\\+1"};
    const std::string COMP_M_MINUS_ONE{"M\\-1"};
    const std::string COMP_D_PLUS_M{"D\\+M"};
    const std::string COMP_D_MINUS_M{"D\\-M"};
    const std::string COMP_M_MINUS_D{"M\\-D"};
    const std::string COMP_D_AND_M{"D\\&M"};
    const std::string COMP_D_OR_M{"D\\|M"};
  }
}

#endif