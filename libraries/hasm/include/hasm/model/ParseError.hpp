#pragma once

#include <hasm/model/Located.hpp>

#include <string>

namespace Hasm::Model
{

/// A line of source code together with its location.
using SourceLine = Located< std::string >;

/// Describes an error encountered while parsing source code.
struct ParseError
{
    SourceLine  line;
    std::string message;
};

} // namespace Hasm::Model
