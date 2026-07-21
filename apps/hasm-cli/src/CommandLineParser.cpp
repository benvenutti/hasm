#include "CommandLineParser.hpp"

#include <CLI/CLI.hpp>

#include <exception>

namespace
{

[[nodiscard]] CommandLineParser::Result parseCommandLine( const int argc, char const* const* argv )
{
    CLI::App app{ "hasm: assembler for the nand2tetris hack platform" };

    CommandLineParser::ParsedArguments parsedArguments;

    app.add_option( "-i,--input-file", parsedArguments.inputFile, "input .asm file" )
        ->required()
        ->check( CLI::ExistingFile );

    app.add_option( "-o,--output-file", parsedArguments.outputFile, "output .hack file" );
    app.add_flag( "-s,--symbol-table", parsedArguments.exportSymbols, "export symbol table (to <input file>.sym)" );
    app.set_version_flag( "-v,--version" );

    try
    {
        app.parse( argc, argv );

        return parsedArguments;
    }
    catch ( const CLI::CallForHelp& )
    {
        return CommandLineParser::RequestToPrintHelp{ app.help() };
    }
    catch ( const CLI::CallForVersion& )
    {
        return CommandLineParser::RequestToPrintVersion{};
    }
}

} // namespace

CommandLineParser::Result CommandLineParser::parse( const int argc, char const* const* argv )
{
    try
    {
        return parseCommandLine( argc, argv );
    }
    catch ( const std::exception& exception )
    {
        return Error{ exception.what() };
    }
    catch ( ... )
    {
        return Error{ "Unknown error" };
    }
}
