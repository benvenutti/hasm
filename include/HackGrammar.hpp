#ifndef HASM_HACKGRAMMAR_HPP
#define HASM_HACKGRAMMAR_HPP

#include <string>

#include "HackLex.hpp"

namespace Hasm {
namespace Hack {
namespace Grammar {

const std::string LABEL{
    Lex::LEFT_PAREN
        + Lex::ID
        + Lex::RIGHT_PAREN
};

const std::string LOAD{
    Lex::AT
        + "("
        + Lex::INTEGER
        + "|"
        + Lex::ID
        + ")"
};

const std::string DESTINATIONS{
    "("
        + Lex::DEST_A
        + "|"
        + Lex::DEST_M
        + "|"
        + Lex::DEST_D
        + "|"
        + Lex::DEST_A
        + Lex::DEST_M
        + "|"
        + Lex::DEST_A
        + Lex::DEST_D
        + "|"
        + Lex::DEST_M
        + Lex::DEST_D
        + "|"
        + Lex::DEST_A
        + Lex::DEST_M
        + Lex::DEST_D
        + ")"
};

const std::string JUMPS{
    "("
        + Lex::JUMP_JGT
        + "|"
        + Lex::JUMP_JGE
        + "|"
        + Lex::JUMP_JLT
        + "|"
        + Lex::JUMP_JLE
        + "|"
        + Lex::JUMP_JEQ
        + "|"
        + Lex::JUMP_JNE
        + "|"
        + Lex::JUMP_JEQ
        + "|"
        + Lex::JUMP_JMP
        + ")"
};

const std::string COMPUTATIONS{
    "("
        + Lex::COMP_ZERO
        + "|"
        + Lex::COMP_ONE
        + "|"
        + Lex::COMP_MINUS_ONE
        + "|"
        + Lex::COMP_D
        + "|"
        + Lex::COMP_A
        + "|"
        + Lex::COMP_NOT_D
        + "|"
        + Lex::COMP_NOT_A
        + "|"
        + Lex::COMP_MINUS_D
        + "|"
        + Lex::COMP_MINUS_A
        + "|"
        + Lex::COMP_D_PLUS_ONE
        + "|"
        + Lex::COMP_A_PLUS_ONE
        + "|"
        + Lex::COMP_D_MINUS_ONE
        + "|"
        + Lex::COMP_A_MINUS_ONE
        + "|"
        + Lex::COMP_D_PLUS_A
        + "|"
        + Lex::COMP_D_MINUS_A
        + "|"
        + Lex::COMP_A_MINUS_D
        + "|"
        + Lex::COMP_D_AND_A
        + "|"
        + Lex::COMP_D_OR_A
        + "|"
        + Lex::COMP_M
        + "|"
        + Lex::COMP_NOT_M
        + "|"
        + Lex::COMP_MINUS_M
        + "|"
        + Lex::COMP_M_PLUS_ONE
        + "|"
        + Lex::COMP_M_MINUS_ONE
        + "|"
        + Lex::COMP_D_PLUS_M
        + "|"
        + Lex::COMP_D_MINUS_M
        + "|"
        + Lex::COMP_M_MINUS_D
        + "|"
        + Lex::COMP_D_AND_M
        + "|"
        + Lex::COMP_D_OR_M
        + ")"
};

const std::string COMPUTATION_COMMAND{
    "("
        + DESTINATIONS
        + Lex::EQUAL
        + ")?"
        + COMPUTATIONS
        + "("
        + Lex::SEMICOLON
        + JUMPS
        + ")?"
};

} // namespace Grammar
} // namespace Hack
} // namespace Hasm

#endif