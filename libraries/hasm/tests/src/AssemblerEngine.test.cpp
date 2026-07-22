#include <hasm/AssemblerEngine.hpp>

#include <catch2/catch_test_macros.hpp>

#include <atomic>
#include <filesystem>
#include <format>
#include <stdexcept>
#include <string_view>

namespace
{

[[nodiscard]] std::filesystem::path validInput( std::string_view name )
{
    return std::filesystem::path{ HASM_TEST_INPUT } / "valid" / name;
}

[[nodiscard]] std::filesystem::path invalidInput( std::string_view name )
{
    return std::filesystem::path{ HASM_TEST_INPUT } / "invalid" / name;
}

[[nodiscard]] std::filesystem::path temporaryOutput( std::string_view name )
{
    static std::atomic_uint counter{};

    return std::filesystem::temp_directory_path() / std::format( "hasm-{}-{}", counter++, name );
}

[[nodiscard]] std::filesystem::path symbolOutput( const std::filesystem::path& output )
{
    auto symbols = output;
    symbols.replace_extension( ".sym" );

    return symbols;
}

[[nodiscard]] Hasm::Assembler::Logger testLogger()
{
    return []( std::string_view ) {};
}

} // namespace

TEST_CASE( "AssemblerEngine::run validates its preconditions" )
{
    const Hasm::AssemblerOptions options{ validInput( "Add.asm" ), temporaryOutput( "Add.hack" ), false };

    REQUIRE_THROWS_AS( Hasm::AssemblerEngine::run( options, {} ), std::logic_error );
}

TEST_CASE( "AssemblerEngine::run validates its input and output paths" )
{
    const auto input  = validInput( "Add.asm" );
    const auto output = temporaryOutput( "Add.hack" );
    const auto logger = testLogger();

    SECTION( "fails if input does not exist" )
    {
        const Hasm::AssemblerOptions options{ invalidInput( "DoesNotExist.asm" ), output, false };

        REQUIRE_FALSE( Hasm::AssemblerEngine::run( options, logger ) );
    }

    SECTION( "fails if input does not have .asm extension" )
    {
        const Hasm::AssemblerOptions options{ invalidInput( "WrongExtension.txt" ), output, false };

        REQUIRE_FALSE( Hasm::AssemblerEngine::run( options, logger ) );
    }

    SECTION( "fails if input and output refer to the same file" )
    {
        const Hasm::AssemblerOptions options{ input, input, false };

        REQUIRE_FALSE( Hasm::AssemblerEngine::run( options, logger ) );
    }

    SECTION( "fails if output does not have .hack extension" )
    {
        const Hasm::AssemblerOptions options{ input, temporaryOutput( "Add.txt" ), false };

        REQUIRE_FALSE( Hasm::AssemblerEngine::run( options, logger ) );
    }

    SECTION( "fails if output cannot be created" )
    {
        const Hasm::AssemblerOptions options{ input, temporaryOutput( "path-does-not-exist" ) / "Add.hack", false };

        REQUIRE_FALSE( Hasm::AssemblerEngine::run( options, logger ) );
    }
}

TEST_CASE( "AssemblerEngine::run assembles a valid program" )
{
    const auto output = temporaryOutput( "Add.hack" );

    const Hasm::AssemblerOptions options{ validInput( "Add.asm" ), output, false };

    REQUIRE( Hasm::AssemblerEngine::run( options, testLogger() ) );
    REQUIRE( std::filesystem::exists( output ) );

    const auto symbols = symbolOutput( output );

    REQUIRE_FALSE( std::filesystem::exists( symbols ) );
}

TEST_CASE( "AssemblerEngine::run exports the symbol table" )
{
    const auto output = temporaryOutput( "Add.hack" );

    const Hasm::AssemblerOptions options{ validInput( "Add.asm" ), output, true };

    REQUIRE( Hasm::AssemblerEngine::run( options, testLogger() ) );
    REQUIRE( std::filesystem::exists( output ) );

    const auto symbols = symbolOutput( output );

    REQUIRE( std::filesystem::exists( symbols ) );
}
