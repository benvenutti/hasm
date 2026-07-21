#include <hasm/AssemblerEngine.hpp>
#include <hasm/AssemblerEngineConfig.hpp>
#include <hasm/HasmInfo.hpp>
#include <utilities/CommandLineParser.hpp>

#include <cstdlib>
#include <format>
#include <iostream>
#include <variant>

struct RequestVisitor
{
    bool operator()( const Utilities::CommandLineParser::Config& config ) const
    {
        try
        {
            const Hasm::AssemblerEngine assembler{ []( const auto& log ) { std::cout << log << std::endl; } };

            return assembler.run( { config.inputFile, config.exportSymbols } );
        }
        catch ( const std::exception& exception )
        {
            std::cerr << exception.what() << std::endl;

            return false;
        }
    }

    bool operator()( const Utilities::CommandLineParser::RequestToPrintHelp& help ) const
    {
        std::cout << help.message << std::endl;

        return true;
    }

    bool operator()( const Utilities::CommandLineParser::RequestToPrintVersion& ) const
    {
        std::cout << std::format( "{} {}", Hasm::projectName, Hasm::Version::full ) << std::endl;

        return true;
    }

    bool operator()( const Utilities::CommandLineParser::Error& error ) const
    {
        std::cerr << error.message << std::endl;

        return true;
    }
};

int main( int argc, char** argv )
{
    const auto userRequest = Utilities::CommandLineParser::parse( argc, argv );

    return std::visit( RequestVisitor{}, userRequest ) ? EXIT_SUCCESS : EXIT_FAILURE;
}
