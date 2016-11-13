#ifndef HASM_COMMANDLINEPARSER_H_
#define HASM_COMMANDLINEPARSER_H_

#include "AssemblerEngineConfig.h"
#include "Hasm.hpp"

namespace Hasm {
  namespace CommandLineParser {
    AssemblerEngineConfig parse(int argc, char const* const* argv);
  };
}

#endif
