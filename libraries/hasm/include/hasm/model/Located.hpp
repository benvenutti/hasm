#pragma once

#include <hasm/model/SourceLocation.hpp>

namespace Hasm::Model
{

/// Associates a parsed value with its source location.
template < typename T >
struct Located
{
    T              value;
    SourceLocation location;
};

} // namespace Hasm::Model
