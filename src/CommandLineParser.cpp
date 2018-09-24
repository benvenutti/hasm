#include "CommandLineParser.hpp"

#include "Version.hpp"

#include <clara.hpp>

#include <iostream>

namespace Hasm
{

boost::optional<Config> CommandLineParser::parse( int argc, char const* const* argv )
{
    Config cfg;
    bool   showVersion{ false };
    bool   showHelp{ false };

    auto cli = clara::Help( showHelp )             //
               | clara::Arg( cfg.source, "souce" ) //
               | clara::Opt( cfg.exportSymbols )["-s"]["--symbol-table"]( "export symbol table (to <source>.sym)" )
               | clara::Opt( showVersion )["-v"]["--version"]( "print version number" );

    const auto result = cli.parse( clara::Args( argc, argv ) );

    if ( !result )
    {
        std::cerr << "Error in command line: " << result.errorMessage() << std::endl;
    }

    if ( showHelp )
    {
        std::cout << Version::string << '\n';
        std::cout << cli << std::endl;
    }
    else if ( showVersion )
    {
        std::cout << Version::string << std::endl;
    }

    if ( !showHelp && !showVersion && result && !cfg.source.empty() )
        return cfg;

    return boost::none;
}

} // namespace Hasm
