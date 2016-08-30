#ifndef HASM_HACKGRAMMAR_H
#define HASM_HACKGRAMMAR_H

#include <string>

#include "HackLex.h"

namespace Hack {
  namespace Grammar {
    const std::string DESTINATIONS{
      "("
        + Hack::Lex::DEST_A
        + "|"
        + Hack::Lex::DEST_M
        + "|"
        + Hack::Lex::DEST_D
        + "|"
        + Hack::Lex::DEST_A
        + Hack::Lex::DEST_M
        + "|"
        + Hack::Lex::DEST_A
        + Hack::Lex::DEST_D
        + "|"
        + Hack::Lex::DEST_M
        + Hack::Lex::DEST_D
        + "|"
        + Hack::Lex::DEST_A
        + Hack::Lex::DEST_M
        + Hack::Lex::DEST_D
        + ")"
    };

    const std::string JUMPS{
      "("
        + Hack::Lex::JUMP_JGT
        + "|"
        + Hack::Lex::JUMP_JGE
        + "|"
        + Hack::Lex::JUMP_JLT
        + "|"
        + Hack::Lex::JUMP_JLE
        + "|"
        + Hack::Lex::JUMP_JEQ
        + "|"
        + Hack::Lex::JUMP_JNE
        + "|"
        + Hack::Lex::JUMP_JEQ
        + "|"
        + Hack::Lex::JUMP_JMP
        + ")"
    };

    const std::string COMPUTATIONS{
      "("
        + Hack::Lex::COMP_ZERO
        + "|"
        + Hack::Lex::COMP_ONE
        + "|"
        + Hack::Lex::COMP_MINUS_ONE
        + "|"
        + Hack::Lex::COMP_D
        + "|"
        + Hack::Lex::COMP_A
        + "|"
        + Hack::Lex::COMP_NOT_D
        + "|"
        + Hack::Lex::COMP_NOT_A
        + "|"
        + Hack::Lex::COMP_MINUS_D
        + "|"
        + Hack::Lex::COMP_MINUS_A
        + "|"
        + Hack::Lex::COMP_D_PLUS_ONE
        + "|"
        + Hack::Lex::COMP_A_PLUS_ONE
        + "|"
        + Hack::Lex::COMP_D_MINUS_ONE
        + "|"
        + Hack::Lex::COMP_A_MINUS_ONE
        + "|"
        + Hack::Lex::COMP_D_PLUS_A
        + "|"
        + Hack::Lex::COMP_D_MINUS_A
        + "|"
        + Hack::Lex::COMP_A_MINUS_D
        + "|"
        + Hack::Lex::COMP_D_AND_A
        + "|"
        + Hack::Lex::COMP_D_OR_A
        + "|"
        + Hack::Lex::COMP_M
        + "|"
        + Hack::Lex::COMP_NOT_M
        + "|"
        + Hack::Lex::COMP_MINUS_M
        + "|"
        + Hack::Lex::COMP_M_PLUS_ONE
        + "|"
        + Hack::Lex::COMP_M_MINUS_ONE
        + "|"
        + Hack::Lex::COMP_D_PLUS_M
        + "|"
        + Hack::Lex::COMP_D_MINUS_M
        + "|"
        + Hack::Lex::COMP_M_MINUS_D
        + "|"
        + Hack::Lex::COMP_D_AND_M
        + "|"
        + Hack::Lex::COMP_D_OR_M
        + ")"
    };
  }
}

#endif