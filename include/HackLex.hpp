#ifndef HASM_HACKLEX_HPP
#define HASM_HACKLEX_HPP

#include <string>

namespace Hasm
{
namespace Hack
{
namespace Lex
{

const std::string ID{ "([[:alpha:]]|\\_|\\.|\\$|\\:)(\\w|\\.|\\$|\\:)*" };
const std::string INTEGER{ "\\d+" };

const std::string AT{ "\\@" };
const std::string SEMICOLON{ "\\;" };
const std::string EQUAL{ "\\=" };
const std::string LEFT_PAREN{ "\\(" };
const std::string RIGHT_PAREN{ "\\)" };
const std::string PLUS{ "\\+" };
const std::string MINUS{ "\\-" };
const std::string NOT{ "\\!" };
const std::string AND{ "\\&" };
const std::string OR{ "\\|" };

const std::string ZERO{ "0" };
const std::string ONE{ "1" };

const std::string DEST_A{ "A" };
const std::string DEST_M{ "M" };
const std::string DEST_D{ "D" };

const std::string JUMP_JGT{ "JGT" };
const std::string JUMP_JGE{ "JGE" };
const std::string JUMP_JLT{ "JLT" };
const std::string JUMP_JLE{ "JLE" };
const std::string JUMP_JEQ{ "JEQ" };
const std::string JUMP_JNE{ "JNE" };
const std::string JUMP_JMP{ "JMP" };

} // namespace Lex
} // namespace Hack
} // namespace Hasm

#endif
