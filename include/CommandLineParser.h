#ifndef HASM_COMMANDLINEPARSER_H_
#define HASM_COMMANDLINEPARSER_H_

#include "AssemblerEngineConfig.h"
#include "Hasm.h"

namespace Hasm {
  namespace CommandLineParser {
    AssemblerEngineConfig parse(int argc, char** argv);
  };
}

#endif
