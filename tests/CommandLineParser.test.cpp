#include "CommandLineParser.hpp"

#include <catch2/catch.hpp>

#include <array>

namespace
{

const auto check_empty_config = []( const auto& cfg ) {
    REQUIRE_FALSE( cfg.isValid() );
    REQUIRE_FALSE( cfg.exportSymbols() );
    REQUIRE( cfg.inputName().empty() );
};

} // anonymous namespace

SCENARIO( "parse flag for filename", "[AssemblerEngineConfig]" )
{
    const auto check = []( const auto& cfg ) {
        REQUIRE( cfg.isValid() );
        REQUIRE_FALSE( cfg.exportSymbols() );
        REQUIRE( cfg.inputName() == std::string{ "input.asm" } );
    };

    constexpr std::array<const char*, 3> argsShorthand{ { "hasm", "-i", "input.asm" } };
    check( Hasm::CommandLineParser::parse( argsShorthand.size(), argsShorthand.data() ) );

    constexpr std::array<const char*, 3> args{ { "hasm", "--input-file", "input.asm" } };
    check( Hasm::CommandLineParser::parse( args.size(), args.data() ) );
}

SCENARIO( "parse flag for symbol table", "[AssemblerEngineConfig]" )
{
    const auto check = []( const auto& cfg ) {
        REQUIRE( cfg.isValid() );
        REQUIRE( cfg.exportSymbols() );
        REQUIRE( cfg.inputName() == std::string{ "input.asm" } );
    };

    constexpr std::array<const char*, 3> argsShorthand{ { "hasm", "-s", "input.asm" } };
    check( Hasm::CommandLineParser::parse( argsShorthand.size(), argsShorthand.data() ) );

    constexpr std::array<const char*, 3> args{ { "hasm", "--symbol-table", "input.asm" } };
    check( Hasm::CommandLineParser::parse( args.size(), args.data() ) );
}

SCENARIO( "parse flag for help", "[AssemblerEngineConfig]" )
{
    constexpr std::array<const char*, 2> argsShorthand{ { "hasm", "-h" } };
    check_empty_config( Hasm::CommandLineParser::parse( argsShorthand.size(), argsShorthand.data() ) );

    constexpr std::array<const char*, 2> args{ { "hasm", "--help" } };
    check_empty_config( Hasm::CommandLineParser::parse( args.size(), args.data() ) );
}

SCENARIO( "parse flag for version", "[AssemblerEngineConfig]" )
{
    constexpr std::array<const char*, 2> argsShorthand{ { "hasm", "-v" } };
    check_empty_config( Hasm::CommandLineParser::parse( argsShorthand.size(), argsShorthand.data() ) );

    constexpr std::array<const char*, 2> args{ { "hasm", "--version" } };
    check_empty_config( Hasm::CommandLineParser::parse( args.size(), args.data() ) );
}

SCENARIO( "parse flag for invalid flag", "[AssemblerEngineConfig]" )
{
    constexpr std::array<const char*, 2> argsShorthand{ { "hasm", "-x" } };
    check_empty_config( Hasm::CommandLineParser::parse( argsShorthand.size(), argsShorthand.data() ) );

    constexpr std::array<const char*, 2> args{ { "hasm", "--invalid_flag" } };
    check_empty_config( Hasm::CommandLineParser::parse( args.size(), args.data() ) );
}

SCENARIO( "missing input files", "[AssemblerEngineConfig]" )
{
    {
        constexpr std::array<const char*, 1> args{ { "hasm" } };
        check_empty_config( Hasm::CommandLineParser::parse( args.size(), args.data() ) );
    }

    {
        constexpr std::array<const char*, 2> args{ { "hasm", "-i" } };
        check_empty_config( Hasm::CommandLineParser::parse( args.size(), args.data() ) );
    }

    {
        constexpr std::array<const char*, 2> args{ { "hasm", "--input-file" } };
        check_empty_config( Hasm::CommandLineParser::parse( args.size(), args.data() ) );
    }
}
