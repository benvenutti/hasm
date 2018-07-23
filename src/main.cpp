#include "AssemblerEngine.hpp"
#include "AssemblerEngineConfig.hpp"
#include "CommandLineParser.hpp"

#include <cstdlib>

int main( int argc, char** argv )
{
    const Hasm::AssemblerEngineConfig config{ Hasm::CommandLineParser::parse( argc, argv ) };
    const Hasm::AssemblerEngine       assembler{};

    return assembler.run( config ) ? EXIT_SUCCESS : EXIT_FAILURE;
}
