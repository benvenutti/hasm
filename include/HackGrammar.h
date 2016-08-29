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
  }
}

#endif