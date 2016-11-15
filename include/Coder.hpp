#ifndef HASM_CODER_HPP
#define HASM_CODER_HPP

#include <string>

#include "Hack.hpp"

namespace Hasm {
namespace Coder {

Hack::WORD dest(const std::string& mnemonic);
Hack::WORD comp(const std::string& mnemonic);
Hack::WORD jump(const std::string& mnemonic);

} // namespace Coder
} // namespace Hasm

#endif
