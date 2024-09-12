#include <utilities/CommandLineParser.hpp>

#include <CLI/CLI.hpp>

#include <exception>

namespace Utilities
{

#pragma warning( push )
#pragma warning( disable : 4702 )

CommandLineParser::Result CommandLineParser::parse( const int argc, char const* const* argv )
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

        return Config{ std::move( inputFile ), exportSymbolTable };
    }
    catch ( const CLI::CallForHelp& )
    {
        return RequestToPrintHelp{ app.help() };
    }
    catch ( const CLI::CallForVersion& )
    {
        return RequestToPrintVersion{};
    }
    catch ( const std::exception& exception )
    {
        return Error{ exception.what() };
    }

    return Error{};
}

#pragma warning( pop )

} // namespace Utilities
