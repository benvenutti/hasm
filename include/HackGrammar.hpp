#pragma once

#include <string>

#include "HackLex.hpp"

namespace Hasm
{
namespace Hack
{
namespace Grammar
{

// clang-format off

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

const std::string COMP_ZERO{Lex::ZERO};

const std::string COMP_ONE{Lex::ONE};

const std::string COMP_MINUS_ONE{Lex::MINUS + Lex::ONE};

const std::string COMP_D{Lex::DEST_D};

const std::string COMP_A{Lex::DEST_A};

const std::string COMP_NOT_D{Lex::NOT + Lex::DEST_D};

const std::string COMP_NOT_A{Lex::NOT + Lex::DEST_A};

const std::string COMP_MINUS_D{Lex::MINUS + Lex::DEST_D};

const std::string COMP_MINUS_A{Lex::MINUS + Lex::DEST_A};

const std::string COMP_D_PLUS_ONE{Lex::DEST_D + Lex::PLUS + Lex::ONE};

const std::string COMP_A_PLUS_ONE{Lex::DEST_A + Lex::PLUS + Lex::ONE};

const std::string COMP_D_MINUS_ONE{Lex::DEST_D + Lex::MINUS + Lex::ONE};

const std::string COMP_A_MINUS_ONE{Lex::DEST_A + Lex::MINUS + Lex::ONE};

const std::string COMP_D_PLUS_A{Lex::DEST_D + Lex::PLUS + Lex::DEST_A};

const std::string COMP_D_MINUS_A{Lex::DEST_D + Lex::MINUS + Lex::DEST_A};

const std::string COMP_A_MINUS_D{Lex::DEST_A + Lex::MINUS + Lex::DEST_D};

const std::string COMP_D_AND_A{Lex::DEST_D + Lex::AND + Lex::DEST_A};

const std::string COMP_D_OR_A{Lex::DEST_D + Lex::OR + Lex::DEST_A};

const std::string COMP_M{Lex::DEST_M};

const std::string COMP_NOT_M{Lex::NOT + Lex::DEST_M};

const std::string COMP_MINUS_M{Lex::MINUS + Lex::DEST_M};

const std::string COMP_M_PLUS_ONE{Lex::DEST_M + Lex::PLUS + Lex::ONE};

const std::string COMP_M_MINUS_ONE{Lex::DEST_M + Lex::MINUS + Lex::ONE};

const std::string COMP_D_PLUS_M{Lex::DEST_D + Lex::PLUS + Lex::DEST_M};

const std::string COMP_D_MINUS_M{Lex::DEST_D + Lex::MINUS + Lex::DEST_M};

const std::string COMP_M_MINUS_D{Lex::DEST_M + Lex::MINUS + Lex::DEST_D};

const std::string COMP_D_AND_M{Lex::DEST_D + Lex::AND + Lex::DEST_M};

const std::string COMP_D_OR_M{Lex::DEST_D + Lex::OR + Lex::DEST_M};

const std::string COMPUTATIONS{
    "("
        + COMP_ZERO
        + "|"
        + COMP_ONE
        + "|"
        + COMP_MINUS_ONE
        + "|"
        + COMP_D
        + "|"
        + COMP_A
        + "|"
        + COMP_NOT_D
        + "|"
        + COMP_NOT_A
        + "|"
        + COMP_MINUS_D
        + "|"
        + COMP_MINUS_A
        + "|"
        + COMP_D_PLUS_ONE
        + "|"
        + COMP_A_PLUS_ONE
        + "|"
        + COMP_D_MINUS_ONE
        + "|"
        + COMP_A_MINUS_ONE
        + "|"
        + COMP_D_PLUS_A
        + "|"
        + COMP_D_MINUS_A
        + "|"
        + COMP_A_MINUS_D
        + "|"
        + COMP_D_AND_A
        + "|"
        + COMP_D_OR_A
        + "|"
        + COMP_M
        + "|"
        + COMP_NOT_M
        + "|"
        + COMP_MINUS_M
        + "|"
        + COMP_M_PLUS_ONE
        + "|"
        + COMP_M_MINUS_ONE
        + "|"
        + COMP_D_PLUS_M
        + "|"
        + COMP_D_MINUS_M
        + "|"
        + COMP_M_MINUS_D
        + "|"
        + COMP_D_AND_M
        + "|"
        + COMP_D_OR_M
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

// clang-format on

} // namespace Grammar
} // namespace Hack
} // namespace Hasm
