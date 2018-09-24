#include "AssemblerEngine.hpp"
#include "CommandLineParser.hpp"

#include <cstdlib>

int main( int argc, char** argv )
{
    if ( const auto cfg = Hasm::CommandLineParser::parse( argc, argv ) )
    {
        return Hasm::AssemblerEngine{}.run( *cfg ) ? EXIT_SUCCESS : EXIT_FAILURE;
    }

    return EXIT_FAILURE;
}
