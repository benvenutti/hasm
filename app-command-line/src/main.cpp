#include <hasm/AssemblerEngine.hpp>
#include <hasm/AssemblerEngineConfig.hpp>
#include <utilities/CommandLineParser.hpp>

#include <cstdlib>
#include <variant>

struct RequestVisitor
{
    bool operator()( const Utilities::CommandLineParser::Config& config ) const
    {
        const Hasm::AssemblerEngine assembler{};

        return assembler.run( { config.inputFile, config.exportSymbols } );
    }

    bool operator()( const auto& ) const
    {
        return false;
    }
};

int main( int argc, char** argv )
{
    const auto userRequest = Utilities::CommandLineParser::parse( argc, argv );

    return std::visit( RequestVisitor{}, userRequest ) ? EXIT_SUCCESS : EXIT_FAILURE;
}
