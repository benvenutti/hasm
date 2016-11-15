#ifndef HASM_COMMANDLINEPARSER_HPP
#define HASM_COMMANDLINEPARSER_HPP

namespace Hasm {

class AssemblerEngineConfig;

namespace CommandLineParser {

AssemblerEngineConfig parse(int argc, char const* const* argv);

} // namespace CommandLineParser
} // namespace Hasm

#endif
