#pragma once

#include <hasm/Hack.hpp>

#include <string>

namespace Hasm::Coder
{

Hack::word dest( const std::string& mnemonic );
Hack::word comp( const std::string& mnemonic );
Hack::word jump( const std::string& mnemonic );

} // namespace Hasm::Coder
