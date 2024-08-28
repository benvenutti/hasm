#include <utilities/CommandLineParser.hpp>

#include <catch2/catch_test_macros.hpp>

#include <array>

SCENARIO( "parse option for filename", "[CommandLineParser]" )
{
    {
        constexpr std::array< const char*, 3 > args{ { "hasm", "-i", "input.asm" } };

        const auto config = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE( config.has_value() );
        REQUIRE_FALSE( config->exportSymbols );
        REQUIRE( config->inputFile == std::filesystem::path{ "input.asm" } );
    }

    {
        constexpr std::array< const char*, 3 > args{ { "hasm", "--input-file", "input.asm" } };

        const auto config = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE( config.has_value() );
        REQUIRE_FALSE( config->exportSymbols );
        REQUIRE( config->inputFile == std::filesystem::path{ "input.asm" } );
    }
}

SCENARIO( "parse option for symbol table", "[CommandLineParser]" )
{
    {
        constexpr std::array< const char*, 4 > args{ { "hasm", "-i", "input.asm", "-s" } };

        const auto config = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE( config.has_value() );
        REQUIRE( config->exportSymbols );
        REQUIRE( config->inputFile == std::filesystem::path{ "input.asm" } );
    }

    {
        constexpr std::array< const char*, 4 > args{ { "hasm", "-i", "input.asm", "--symbol-table" } };

        const auto config = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE( config.has_value() );
        REQUIRE( config->exportSymbols );
        REQUIRE( config->inputFile == std::filesystem::path{ "input.asm" } );
    }
}

SCENARIO( "parse option for symbol table without an input file", "[CommandLineParser]" )
{
    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "-s" } };

        const auto config = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE_FALSE( config.has_value() );
    }

    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "--symbol-table" } };

        const auto config = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE_FALSE( config.has_value() );
    }
}

SCENARIO( "parse option for help", "[CommandLineParser]" )
{
    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "-h" } };

        const auto config = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE_FALSE( config.has_value() );
    }

    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "--help" } };

        const auto config = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE_FALSE( config.has_value() );
    }
}

SCENARIO( "parse option for version", "[CommandLineParser]" )
{
    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "-v" } };

        const auto config = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE_FALSE( config.has_value() );
    }

    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "--version" } };

        const auto config = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE_FALSE( config.has_value() );
    }
}

SCENARIO( "parse invalid option", "[CommandLineParser]" )
{
    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "-x" } };

        const auto config = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE_FALSE( config.has_value() );
    }

    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "--invalid_flag" } };

        const auto config = Utilities::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE_FALSE( config.has_value() );
    }
}
