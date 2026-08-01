#pragma once

#include <hasm/language/Lex.hpp>

#include <regex>
#include <string>

namespace Hasm::Language::Grammar
{

inline const std::regex label{ std::string{ Lex::leftParen }    //
                               + std::string{ Lex::identifier } //
                               + std::string{ Lex::rightParen } };

inline const std::regex addressInstruction{ std::string{ Lex::at }           //
                                            + "("                            //
                                            + std::string{ Lex::integer }    //
                                            + "|"                            //
                                            + std::string{ Lex::identifier } //
                                            + ")" };

} // namespace Hasm::Language::Grammar
