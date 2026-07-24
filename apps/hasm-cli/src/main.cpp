#include "CommandLineParser.hpp"

#include <hasm/AssemblerEngine.hpp>
#include <hasm/HasmInfo.hpp>

#include <cstdlib>
#include <format>
#include <iostream>
#include <variant>

namespace
{

[[nodiscard]] Hasm::AssemblerOptions makeAssemblerOptions( const CommandLineParser::ParsedArguments& parsedArguments )
{
    // When the user does not specify an output file, write to
    // the input file with the .hack extension.

    auto outputFile = parsedArguments.outputFile.value_or(
        std::filesystem::path( parsedArguments.inputFile ).replace_extension( ".hack" ) );

    return { parsedArguments.inputFile, std::move( outputFile ), parsedArguments.exportSymbols };
}

struct RequestVisitor
{
    bool operator()( const CommandLineParser::ParsedArguments& parsedArguments ) const
    {
        const auto logger = []( const auto& message ) { std::cout << message << '\n'; };
        return Hasm::AssemblerEngine::run( makeAssemblerOptions( parsedArguments ), logger );
    }

    bool operator()( const CommandLineParser::RequestToPrintHelp& help ) const
    {
        std::cout << help.message << std::endl;
        return true;
    }

    bool operator()( const CommandLineParser::RequestToPrintVersion& ) const
    {
        std::cout << std::format( "{} {}", Hasm::projectName, Hasm::Version::full ) << std::endl;
        return true;
    }

    bool operator()( const CommandLineParser::Error& error ) const
    {
        std::cerr << error.message << std::endl;
        return false;
    }
};

} // namespace

int main( const int argc, char* argv[] )
{
    const auto userRequest = CommandLineParser::parse( argc, argv );

    return std::visit( RequestVisitor{}, userRequest ) ? EXIT_SUCCESS : EXIT_FAILURE;
}
