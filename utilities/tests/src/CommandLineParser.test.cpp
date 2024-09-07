#include <utilities/CommandLineParser.hpp>

#include <catch2/catch_test_macros.hpp>

#include <array>

SCENARIO( "parse option for filename", "[CommandLineParser]" )
{
    {
        constexpr std::array< const char*, 3 > args{ { "hasm", "-i", "input.asm" } };

        const auto result = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE( std::holds_alternative< Utilities::CommandLineParser::Config >( result ) );

        const auto& config = std::get< Utilities::CommandLineParser::Config >( result );

        REQUIRE_FALSE( config.exportSymbols );
        REQUIRE( config.inputFile == std::filesystem::path{ "input.asm" } );
    }

    {
        constexpr std::array< const char*, 3 > args{ { "hasm", "--input-file", "input.asm" } };

        const auto result = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE( std::holds_alternative< Utilities::CommandLineParser::Config >( result ) );

        const auto& config = std::get< Utilities::CommandLineParser::Config >( result );

        REQUIRE_FALSE( config.exportSymbols );
        REQUIRE( config.inputFile == std::filesystem::path{ "input.asm" } );
    }
}

SCENARIO( "parse option for symbol table", "[CommandLineParser]" )
{
    {
        constexpr std::array< const char*, 4 > args{ { "hasm", "-i", "input.asm", "-s" } };

        const auto result = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE( std::holds_alternative< Utilities::CommandLineParser::Config >( result ) );

        const auto& config = std::get< Utilities::CommandLineParser::Config >( result );

        REQUIRE( config.exportSymbols );
        REQUIRE( config.inputFile == std::filesystem::path{ "input.asm" } );
    }

    {
        constexpr std::array< const char*, 4 > args{ { "hasm", "-i", "input.asm", "--symbol-table" } };

        const auto result = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE( std::holds_alternative< Utilities::CommandLineParser::Config >( result ) );

        const auto& config = std::get< Utilities::CommandLineParser::Config >( result );

        REQUIRE( config.exportSymbols );
        REQUIRE( config.inputFile == std::filesystem::path{ "input.asm" } );
    }
}

SCENARIO( "parse option for symbol table without an input file", "[CommandLineParser]" )
{
    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "-s" } };

        const auto result = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE_FALSE( std::holds_alternative< Utilities::CommandLineParser::Config >( result ) );
    }

    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "--symbol-table" } };

        const auto result = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE_FALSE( std::holds_alternative< Utilities::CommandLineParser::Config >( result ) );
    }
}

SCENARIO( "parse option for help", "[CommandLineParser]" )
{
    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "-h" } };

        const auto result = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE( std::holds_alternative< Utilities::CommandLineParser::RequestToPrintHelp >( result ) );
    }

    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "--help" } };

        const auto result = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE( std::holds_alternative< Utilities::CommandLineParser::RequestToPrintHelp >( result ) );
    }
}

SCENARIO( "parse option for version", "[CommandLineParser]" )
{
    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "-v" } };

        const auto result = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE( std::holds_alternative< Utilities::CommandLineParser::RequestToPrintVersion >( result ) );
    }

    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "--version" } };

        const auto result = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE( std::holds_alternative< Utilities::CommandLineParser::RequestToPrintVersion >( result ) );
    }
}

SCENARIO( "parse invalid option", "[CommandLineParser]" )
{
    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "-x" } };

        const auto result = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE( std::holds_alternative< Utilities::CommandLineParser::Error >( result ) );
    }

    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "--invalid_flag" } };

        const auto result = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE( std::holds_alternative< Utilities::CommandLineParser::Error >( result ) );
    }
}
