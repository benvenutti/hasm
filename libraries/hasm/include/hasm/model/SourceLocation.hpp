#pragma once

#include <cstddef>

namespace Hasm::Model
{

/// Represents a location within the source being parsed.
struct SourceLocation
{
    std::size_t line{};
};

} // namespace Hasm::Model
