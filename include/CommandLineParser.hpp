#pragma once

namespace Hasm
{

class AssemblerEngineConfig;

namespace CommandLineParser
{

AssemblerEngineConfig parse( int argc, char const* const* argv );

} // namespace CommandLineParser
} // namespace Hasm
