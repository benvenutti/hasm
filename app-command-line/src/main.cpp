#include <hasm/AssemblerEngine.hpp>
#include <hasm/AssemblerEngineConfig.hpp>
#include <utilities/CommandLineParser.hpp>

#include <cstdlib>

int main( int argc, char** argv )
{
    if ( const auto config = Utilities::CommandLineParser::parse( argc, argv ) )
    {
        const Hasm::AssemblerEngine assembler{};

        return assembler.run( { config->inputFile, config->exportSymbols } ) ? EXIT_SUCCESS : EXIT_FAILURE;
    }

    return EXIT_FAILURE;
}
