#include "CommandLineParser.hpp"

#include "HasmConfig.hpp"

#include <clara.hpp>

#include <iostream>

namespace Hasm
{

AssemblerEngineConfig CommandLineParser::parse( int argc, char const* const* argv )
{
    std::string inputName{ "" };
    bool        symtable{ false };
    bool        showVersion{ false };
    bool        showHelp{ false };

    auto cli = clara::Arg( inputName, "source" ) //
               | clara::Opt( symtable )["-s"]["--symbol-table"]( "export symbol table (to <infile>.sym)" )
               | clara::Opt( showVersion )["-v"]["--version"]( "print version number" ) //
               | clara::Help( showHelp );

    auto result = cli.parse( clara::Args( argc, argv ) );
    if ( !result )
    {
        std::cerr << "Error in command line: " << result.errorMessage() << std::endl;
    }

    if ( showHelp )
    {
        std::cout << cli << std::endl;
    }

    if ( showVersion )
    {
        std::cout << "hasm " << Config::VERSION_MAJOR << "." << Config::VERSION_MINOR << "." << Config::VERSION_PATCH
                  << std::endl;
    }

    const bool isValid = !showHelp && !showVersion && result && !inputName.empty();

    return AssemblerEngineConfig{ isValid, symtable, inputName };
}

} // namespace Hasm
