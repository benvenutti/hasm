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
  }
}

#endif