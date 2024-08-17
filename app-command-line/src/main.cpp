#include <hasm/AssemblerEngine.hpp>
#include <hasm/AssemblerEngineConfig.hpp>
#include <hasm/CommandLineParser.hpp>

#include <cstdlib>

int main( int argc, char** argv )
{
    if ( const auto config = Hasm::CommandLineParser::parse( argc, argv ) )
    {
        const Hasm::AssemblerEngine assembler{};

        return assembler.run( config.value() ) ? EXIT_SUCCESS : EXIT_FAILURE;
    }

    return EXIT_FAILURE;
}
