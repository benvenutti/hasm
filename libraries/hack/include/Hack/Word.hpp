#pragma once

#include <cstdint>

namespace Hack
{

using word = uint16_t;

} // namespace Hack

constexpr Hack::word operator"" _w( unsigned long long value )
{
    return static_cast< Hack::word >( value );
}
