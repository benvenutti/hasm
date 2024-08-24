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

const std::string label{
    Lex::left_paren
        + Lex::id
        + Lex::right_paren
};

const std::string load{
    Lex::at
        + "("
        + Lex::integer
        + "|"
        + Lex::id
        + ")"
};

const std::string destinations{
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

const std::string jumps{
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

const std::string comp_zero{Lex::zero};

const std::string comp_one{Lex::one};

const std::string comp_minus_one{Lex::minus + Lex::one};

const std::string comp_D{Lex::dest_D};

const std::string comp_A{Lex::dest_A};

const std::string comp_not_D{Lex::not_ + Lex::dest_D};

const std::string comp_not_A{Lex::not_ + Lex::dest_A};

const std::string comp_minus_D{Lex::minus + Lex::dest_D};

const std::string comp_minus_A{Lex::minus + Lex::dest_A};

const std::string comp_D_plus_one{Lex::dest_D + Lex::plus + Lex::one};

const std::string comp_A_plus_one{Lex::dest_A + Lex::plus + Lex::one};

const std::string comp_D_minus_one{Lex::dest_D + Lex::minus + Lex::one};

const std::string comp_A_minus_one{Lex::dest_A + Lex::minus + Lex::one};

const std::string comp_D_plus_A{Lex::dest_D + Lex::plus + Lex::dest_A};

const std::string comp_D_minus_A{Lex::dest_D + Lex::minus + Lex::dest_A};

const std::string comp_A_minus_D{Lex::dest_A + Lex::minus + Lex::dest_D};

const std::string comp_D_and_A{Lex::dest_D + Lex::and_ + Lex::dest_A};

const std::string comp_D_or_A{Lex::dest_D + Lex::or_ + Lex::dest_A};

const std::string comp_M{Lex::dest_M};

const std::string comp_not_M{Lex::not_ + Lex::dest_M};

const std::string comp_minus_M{Lex::minus + Lex::dest_M};

const std::string comp_M_plus_one{Lex::dest_M + Lex::plus + Lex::one};

const std::string comp_M_minus_one{Lex::dest_M + Lex::minus + Lex::one};

const std::string comp_D_plus_M{Lex::dest_D + Lex::plus + Lex::dest_M};

const std::string comp_D_minus_M{Lex::dest_D + Lex::minus + Lex::dest_M};

const std::string comp_M_minus_D{Lex::dest_M + Lex::minus + Lex::dest_D};

const std::string comp_D_and_M{Lex::dest_D + Lex::and_ + Lex::dest_M};

const std::string comp_D_or_M{Lex::dest_D + Lex::or_ + Lex::dest_M};

const std::string computations{
    "("
        + comp_zero
        + "|"
        + comp_one
        + "|"
        + comp_minus_one
        + "|"
        + comp_D
        + "|"
        + comp_A
        + "|"
        + comp_not_D
        + "|"
        + comp_not_A
        + "|"
        + comp_minus_D
        + "|"
        + comp_minus_A
        + "|"
        + comp_D_plus_one
        + "|"
        + comp_A_plus_one
        + "|"
        + comp_D_minus_one
        + "|"
        + comp_A_minus_one
        + "|"
        + comp_D_plus_A
        + "|"
        + comp_D_minus_A
        + "|"
        + comp_A_minus_D
        + "|"
        + comp_D_and_A
        + "|"
        + comp_D_or_A
        + "|"
        + comp_M
        + "|"
        + comp_not_M
        + "|"
        + comp_minus_M
        + "|"
        + comp_M_plus_one
        + "|"
        + comp_M_minus_one
        + "|"
        + comp_D_plus_M
        + "|"
        + comp_D_minus_M
        + "|"
        + comp_M_minus_D
        + "|"
        + comp_D_and_M
        + "|"
        + comp_D_or_M
        + ")"
};

const std::string computation_command{
    "("
        + destinations
        + Lex::equal
        + ")?"
        + computations
        + "("
        + Lex::semicolon
        + jumps
        + ")?"
};

// clang-format on

} // namespace Grammar
} // namespace Hack
} // namespace Hasm
