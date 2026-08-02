#include <hasm/parser/InstructionParser.hpp>

#include "hasm/language/Grammar.hpp"

#include <charconv>
#include <regex>

namespace
{

std::expected< Hasm::Model::Symbol, std::string > parseSymbol( const std::string_view text )
{
    static const std::regex identifierRegex{ std::string{ Hasm::Language::Lex::identifier } };

    if ( !std::regex_match( text.begin(), text.end(), identifierRegex ) )
    {
        return std::unexpected( "error" );
    }

    return Hasm::Model::Symbol{ .name = std::string{ text } };
}

std::expected< Hasm::Model::Literal, std::string > parseLiteral( const std::string_view text )
{
    const char* const begin = text.data();
    const char* const end   = begin + text.size();

    uint16_t value{};
 
    if ( const auto result = std::from_chars( begin, end, value ); result.ec != std::errc{} || result.ptr != end )
    {
        return std::unexpected( "error" );
    }

    return Hasm::Model::Literal{ .value = value };
}

std::expected< Hasm::Model::Label, std::string > parseLabel( const std::string_view text )
{
    if ( !text.starts_with( '(' ) || !text.ends_with( ')' ) )
    {
        return std::unexpected( "error" );
    }

    if ( text.size() < 3 )
    {
        return std::unexpected( "error" );
    }

    auto symbol = parseSymbol( text.substr( 1, text.size() - 2 ) );

    if ( !symbol )
    {
        return std::unexpected( std::move( symbol.error() ) );
    }

    return Hasm::Model::Label{ .symbol = std::move( *symbol ) };
}

std::expected< Hasm::Model::AddressInstruction, std::string > parseAddressInstruction( const std::string_view text )
{
    if ( !text.starts_with( '@' ) )
    {
        return std::unexpected( "error" );
    }

    if ( text.size() < 2 )
    {
        return std::unexpected( "error" );
    }

    const auto operand = text.substr( 1 );

    if ( std::isdigit( static_cast< unsigned char >( operand.front() ) ) )
    {
        auto literal = parseLiteral( operand );

        if ( !literal )
        {
            return std::unexpected( std::move( literal.error() ) );
        }

        return Hasm::Model::AddressInstruction{ .operand = *literal };
    }

    auto symbol = parseSymbol( operand );

    if ( !symbol )
    {
        return std::unexpected( std::move( symbol.error() ) );
    }

    return Hasm::Model::AddressInstruction{ .operand = std::move( *symbol ) };
}

} // namespace

namespace Hasm::Parser
{

ParseResult parse( const std::string_view text )
{
    if ( text.starts_with( '(' ) )
    {
        return parseLabel( text );
    }

    if ( text.starts_with( '@' ) )
    {
        return parseAddressInstruction( text );
    }

    return std::unexpected( "error" );
}

} // namespace Hasm::Parser
