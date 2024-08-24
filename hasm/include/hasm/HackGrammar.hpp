#pragma once

#include "HackLex.hpp"

#include <string>

namespace Hasm
{
namespace Hack
{
namespace Grammar
{

// clang-format off

const std::string LABEL{
    Lex::left_paren
        + Lex::id
        + Lex::right_paren
};

const std::string LOAD{
    Lex::at
        + "("
        + Lex::integer
        + "|"
        + Lex::id
        + ")"
};

const std::string DESTINATIONS{
    "("
        + Lex::dest_A
        + "|"
        + Lex::dest_M
        + "|"
        + Lex::dest_D
        + "|"
        + Lex::dest_A
        + Lex::dest_M
        + "|"
        + Lex::dest_A
        + Lex::dest_D
        + "|"
        + Lex::dest_M
        + Lex::dest_D
        + "|"
        + Lex::dest_A
        + Lex::dest_M
        + Lex::dest_D
        + ")"
};

const std::string JUMPS{
    "("
        + Lex::jump_JGT
        + "|"
        + Lex::jump_JGE
        + "|"
        + Lex::jump_JLT
        + "|"
        + Lex::jump_JLE
        + "|"
        + Lex::jump_JEQ
        + "|"
        + Lex::jump_JNE
        + "|"
        + Lex::jump_JEQ
        + "|"
        + Lex::jump_JMP
        + ")"
};

const std::string COMP_ZERO{Lex::zero};

const std::string COMP_ONE{Lex::one};

const std::string COMP_MINUS_ONE{Lex::minus + Lex::one};

const std::string COMP_D{Lex::dest_D};

const std::string COMP_A{Lex::dest_A};

const std::string COMP_NOT_D{Lex::not_ + Lex::dest_D};

const std::string COMP_NOT_A{Lex::not_ + Lex::dest_A};

const std::string COMP_MINUS_D{Lex::minus + Lex::dest_D};

const std::string COMP_MINUS_A{Lex::minus + Lex::dest_A};

const std::string COMP_D_PLUS_ONE{Lex::dest_D + Lex::plus + Lex::one};

const std::string COMP_A_PLUS_ONE{Lex::dest_A + Lex::plus + Lex::one};

const std::string COMP_D_MINUS_ONE{Lex::dest_D + Lex::minus + Lex::one};

const std::string COMP_A_MINUS_ONE{Lex::dest_A + Lex::minus + Lex::one};

const std::string COMP_D_PLUS_A{Lex::dest_D + Lex::plus + Lex::dest_A};

const std::string COMP_D_MINUS_A{Lex::dest_D + Lex::minus + Lex::dest_A};

const std::string COMP_A_MINUS_D{Lex::dest_A + Lex::minus + Lex::dest_D};

const std::string COMP_D_AND_A{Lex::dest_D + Lex::and_ + Lex::dest_A};

const std::string COMP_D_OR_A{Lex::dest_D + Lex::or_ + Lex::dest_A};

const std::string COMP_M{Lex::dest_M};

const std::string COMP_NOT_M{Lex::not_ + Lex::dest_M};

const std::string COMP_MINUS_M{Lex::minus + Lex::dest_M};

const std::string COMP_M_PLUS_ONE{Lex::dest_M + Lex::plus + Lex::one};

const std::string COMP_M_MINUS_ONE{Lex::dest_M + Lex::minus + Lex::one};

const std::string COMP_D_PLUS_M{Lex::dest_D + Lex::plus + Lex::dest_M};

const std::string COMP_D_MINUS_M{Lex::dest_D + Lex::minus + Lex::dest_M};

const std::string COMP_M_MINUS_D{Lex::dest_M + Lex::minus + Lex::dest_D};

const std::string COMP_D_AND_M{Lex::dest_D + Lex::and_ + Lex::dest_M};

const std::string COMP_D_OR_M{Lex::dest_D + Lex::or_ + Lex::dest_M};

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
        + Lex::equal
        + ")?"
        + COMPUTATIONS
        + "("
        + Lex::semicolon
        + JUMPS
        + ")?"
};

// clang-format on

} // namespace Grammar
} // namespace Hack
} // namespace Hasm
