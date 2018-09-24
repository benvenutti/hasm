#pragma once

#include "Config.hpp"

#include <boost/optional.hpp>

namespace Hasm
{
namespace CommandLineParser
{

boost::optional<Config> parse( int argc, char const* const* argv );

} // namespace CommandLineParser
} // namespace Hasm
