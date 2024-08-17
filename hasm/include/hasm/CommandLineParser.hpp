#pragma once

#include <hasm/AssemblerEngineConfig.hpp>

#include <optional>

namespace Hasm::CommandLineParser
{

std::optional< AssemblerEngineConfig > parse( int argc, char const* const* argv );

} // namespace Hasm::CommandLineParser
