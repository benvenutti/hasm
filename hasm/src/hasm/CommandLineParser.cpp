#include <hasm/CommandLineParser.hpp>

#include <hasm/HasmConfig.hpp>

#include <CLI/CLI.hpp>
#include <boost/program_options.hpp>

#include <cassert>
#include <filesystem>
#include <iostream>

namespace Hasm
{

std::optional< AssemblerEngineConfig > CommandLineParser::parse( const int argc, char const* const* argv )
{
    bool                  exportSymbolTable{ false };
    std::filesystem::path inputFile{};

    try
    {
        namespace po = boost::program_options;

        po::options_description desc{ "Allowed options" };

        desc.add_options()                                                                          //
            ( "symbol-table,s", "export symbol table (to <input file>.sym)" )                       //
            ( "input-file,i", po::value< std::filesystem::path >( &inputFile ), "input .asm file" ) //
            ( "help,h", "print this help message" )( "version,v", "print version number" );

        po::positional_options_description positionalDescription{};
        const int                          maxNumberOfInputFiles{ 1 };
        positionalDescription.add( "input-file", maxNumberOfInputFiles );

        po::variables_map       vm{};
        po::command_line_parser parser{ argc, argv };
        po::store( parser.options( desc ).positional( positionalDescription ).run(), vm );
        po::notify( vm );

        if ( vm.count( "help" ) > 0u )
        {
            std::cout << "Usage: hasm [options] <input file>.asm" << std::endl;
            std::cout << desc;

            return std::nullopt;
        }

        if ( vm.count( "version" ) > 0u )
        {
            std::cout << "hasm " << Config::VERSION_MAJOR << "." << Config::VERSION_MINOR << "."
                      << Config::VERSION_PATCH << std::endl;

            return std::nullopt;
        }

        if ( vm.count( "input-file" ) == 0u || inputFile.empty() )
        {
            std::cerr << "hasm: no input file" << std::endl;

            return std::nullopt;
        }

        exportSymbolTable = vm.count( "symbol-table" ) > 0u;
    }
    catch ( const std::exception& exception )
    {
        std::cerr << exception.what() << std::endl;

        return std::nullopt;
    }

    assert( !inputFile.empty() );

    return AssemblerEngineConfig{ std::move( inputFile ), exportSymbolTable };
}

} // namespace Hasm
