#pragma once

#include <string>

namespace Hasm::Lex
{

const std::string id{ "([[:alpha:]]|_|\\.|\\$|:)(\\w|\\.|\\$|:)*" };
const std::string integer{ "\\d+" };

const std::string line_comment{ "//" };

const std::string at{ "@" };
const std::string semicolon{ ";" };
const std::string equal{ "=" };
const std::string left_paren{ "\\(" };
const std::string right_paren{ "\\)" };
const std::string plus{ "\\+" };
const std::string minus{ "\\-" };
const std::string not_{ "\\!" };
const std::string and_{ "&" };
const std::string or_{ "\\|" };

const std::string zero{ "0" };
const std::string one{ "1" };

const std::string dest_A{ "A" };
const std::string dest_M{ "M" };
const std::string dest_D{ "D" };

const std::string jump_JGT{ "JGT" };
const std::string jump_JGE{ "JGE" };
const std::string jump_JLT{ "JLT" };
const std::string jump_JLE{ "JLE" };
const std::string jump_JEQ{ "JEQ" };
const std::string jump_JNE{ "JNE" };
const std::string jump_JMP{ "JMP" };

} // namespace Hasm::Lex
