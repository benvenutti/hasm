#pragma once

#include <Hack/Word.hpp>

#include <limits>

namespace Hack
{

constexpr Hack::word init_ram_address{ 16_w };

// max value for unsigned 15 bit number
constexpr Hack::word max_loadable_value = std::numeric_limits< Hack::word >::max() >> 1;

} // namespace Hack
