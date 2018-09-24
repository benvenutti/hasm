#pragma once

#include "AssemblerEngineConfig.hpp"

#include <boost/optional.hpp>

namespace Hasm
{
namespace CommandLineParser
{

boost::optional<EngineConfig> parse( int argc, char const* const* argv );

} // namespace CommandLineParser
} // namespace Hasm
