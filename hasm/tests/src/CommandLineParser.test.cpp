#include <hasm/CommandLineParser.hpp>

#include <catch2/catch_test_macros.hpp>

#include <array>

SCENARIO( "parse option for filename", "[CommandLineParser]" )
{
    {
        constexpr std::array< const char*, 3 > args{ { "hasm", "-i", "input.asm" } };

        const auto config = Hasm::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE( config.has_value() );
        REQUIRE_FALSE( config->exportSymbols() );
        REQUIRE( config->inputFile() == std::filesystem::path{ "input.asm" } );
    }

    {
        constexpr std::array< const char*, 3 > args{ { "hasm", "--input-file", "input.asm" } };

        const auto config = Hasm::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE( config.has_value() );
        REQUIRE_FALSE( config->exportSymbols() );
        REQUIRE( config->inputFile() == std::filesystem::path{ "input.asm" } );
    }
}

SCENARIO( "parse option for symbol table", "[CommandLineParser]" )
{
    {
        constexpr std::array< const char*, 3 > args{ { "hasm", "-s", "input.asm" } };

        const auto config = Hasm::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE( config.has_value() );
        REQUIRE( config->exportSymbols() );
        REQUIRE( config->inputFile() == std::filesystem::path{ "input.asm" } );
    }

    {
        constexpr std::array< const char*, 3 > args{ { "hasm", "--symbol-table", "input.asm" } };

        const auto config = Hasm::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE( config.has_value() );
        REQUIRE( config->exportSymbols() );
        REQUIRE( config->inputFile() == std::filesystem::path{ "input.asm" } );
    }
}

SCENARIO( "parse option for help", "[CommandLineParser]" )
{
    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "-h" } };

        const auto config = Hasm::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE_FALSE( config.has_value() );
    }

    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "--help" } };

        const auto config = Hasm::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE_FALSE( config.has_value() );
    }
}

SCENARIO( "parse option for version", "[CommandLineParser]" )
{
    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "-v" } };

        const auto config = Hasm::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE_FALSE( config.has_value() );
    }

    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "--version" } };

        const auto config = Hasm::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE_FALSE( config.has_value() );
    }
}

SCENARIO( "parse invalid option", "[CommandLineParser]" )
{
    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "-x" } };

        const auto config = Hasm::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE_FALSE( config.has_value() );
    }

    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "--invalid_flag" } };

        const auto config = Hasm::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE_FALSE( config.has_value() );
    }
}

SCENARIO( "missing input files", "[CommandLineParser]" )
{
    {
        constexpr std::array< const char*, 1 > args{ { "hasm" } };

        const auto config = Hasm::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE_FALSE( config.has_value() );
    }

    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "-i" } };

        const auto config = Hasm::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE_FALSE( config.has_value() );
    }

    {
        constexpr std::array< const char*, 2 > args{ { "hasm", "--input-file" } };

        const auto config = Hasm::CommandLineParser::parse( args.size(), args.data() );

        REQUIRE_FALSE( config.has_value() );
    }
}
