#pragma once

#include <hasm/Hack.hpp>

#include <string>

namespace Hasm::Coder
{

[[nodiscard]] Hack::word dest( const std::string& mnemonic );
[[nodiscard]] Hack::word comp( const std::string& mnemonic );
[[nodiscard]] Hack::word jump( const std::string& mnemonic );

} // namespace Hasm::Coder
