#include <utilities/CommandLineParser.hpp>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include <array>

TEST_CASE( "parse option for filename", "[CommandLineParser]" )
{
    const auto args = GENERATE( std::array< const char*, 3 >{ "hasm", "-i", "input.asm" },
                                std::array< const char*, 3 >{ "hasm", "--input-file", "input.asm" } );

    CAPTURE( args );

    const auto result = Utilities::CommandLineParser::parse( static_cast< int >( args.size() ), args.data() );

    REQUIRE( std::holds_alternative< Utilities::CommandLineParser::Config >( result ) );

    const auto& config = std::get< Utilities::CommandLineParser::Config >( result );

    REQUIRE_FALSE( config.exportSymbols );
    REQUIRE( config.inputFile == std::filesystem::path{ "input.asm" } );
}

TEST_CASE( "parse option for symbol table", "[CommandLineParser]" )
{
    const auto args = GENERATE( std::array< const char*, 4 >{ "hasm", "-i", "input.asm", "-s" },
                                std::array< const char*, 4 >{ "hasm", "--input-file", "input.asm", "--symbol-table" } );

    CAPTURE( args );

    const auto result = Utilities::CommandLineParser::parse( static_cast< int >( args.size() ), args.data() );

    REQUIRE( std::holds_alternative< Utilities::CommandLineParser::Config >( result ) );

    const auto& config = std::get< Utilities::CommandLineParser::Config >( result );

    REQUIRE( config.exportSymbols );
    REQUIRE( config.inputFile == std::filesystem::path{ "input.asm" } );
}

TEST_CASE( "parse option for symbol table without an input file", "[CommandLineParser]" )
{
    const auto args = GENERATE( std::array< const char*, 2 >{ "hasm", "-s" },
                                std::array< const char*, 2 >{ "hasm", "--symbol-table" } );

    const auto result = Utilities::CommandLineParser::parse( static_cast< int >( args.size() ), args.data() );

    REQUIRE_FALSE( std::holds_alternative< Utilities::CommandLineParser::Config >( result ) );
}

TEST_CASE( "parse option for help", "[CommandLineParser]" )
{
    const auto args = GENERATE( std::array< const char*, 2 >{ "hasm", "-h" }, //
                                std::array< const char*, 2 >{ "hasm", "--help" } );

    const auto result = Utilities::CommandLineParser::parse( static_cast< int >( args.size() ), args.data() );

    REQUIRE( std::holds_alternative< Utilities::CommandLineParser::RequestToPrintHelp >( result ) );
}

TEST_CASE( "parse option for version", "[CommandLineParser]" )
{
    const auto args = GENERATE( std::array< const char*, 2 >{ "hasm", "-v" }, //
                                std::array< const char*, 2 >{ "hasm", "--version" } );

    const auto result = Utilities::CommandLineParser::parse( static_cast< int >( args.size() ), args.data() );

    REQUIRE( std::holds_alternative< Utilities::CommandLineParser::RequestToPrintVersion >( result ) );
}

TEST_CASE( "parse invalid option", "[CommandLineParser]" )
{
    const auto args = GENERATE( std::array< const char*, 2 >{ "hasm", "-x" }, //
                                std::array< const char*, 2 >{ "hasm", "--invalid-flag" } );

    const auto result = Utilities::CommandLineParser::parse( static_cast< int >( args.size() ), args.data() );

    REQUIRE( std::holds_alternative< Utilities::CommandLineParser::Error >( result ) );
}
