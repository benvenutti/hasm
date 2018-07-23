#pragma once

#include "Hack.hpp"

#include <string>

namespace Hasm
{
namespace Coder
{

Hack::word dest( const std::string& mnemonic );
Hack::word comp( const std::string& mnemonic );
Hack::word jump( const std::string& mnemonic );

} // namespace Coder
} // namespace Hasm
