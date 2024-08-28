#include <hasm/CommandLineParser.hpp>

#include <hasm/HasmConfig.hpp>

#include <CLI/CLI.hpp>

#include <filesystem>
#include <iostream>

namespace Hasm
{

std::optional< AssemblerEngineConfig > CommandLineParser::parse( const int argc, char const* const* argv )
{
    CLI::App app{ "hasm: assembler for the nand2tetris hack platform" };

    std::filesystem::path inputFile{};
    const auto            inputFileOption = app.add_option( "-i,--input-file", inputFile, "input .asm file" );

    bool exportSymbolTable{ false };
    app.add_flag( "-s,--symbol-table", exportSymbolTable, "export symbol table (to <input file>.sym)" )
        ->needs( inputFileOption );

    app.set_version_flag( "-v,--version" );

    try
    {
        app.parse( argc, argv );

        return AssemblerEngineConfig{ std::move( inputFile ), exportSymbolTable };
    }
    catch ( const CLI::CallForHelp& )
    {
        std::cout << app.help() << std::endl;
    }
    catch ( const CLI::CallForVersion& )
    {
        std::cout << "hasm " << Config::VERSION_MAJOR << "." << Config::VERSION_MINOR << "." << Config::VERSION_PATCH
                  << std::endl;
    }
    catch ( const std::exception& exception )
    {
        std::cerr << exception.what() << std::endl;
    }
    catch ( ... )
    {
    }

    return std::nullopt;
}

} // namespace Hasm
