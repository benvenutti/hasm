#include <hasm/parser/InstructionParser.hpp>

#include "hasm/language/Grammar.hpp"

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

} // namespace

namespace Hasm::Parser
{

ParseResult parse( const std::string_view text )
{
    if ( text.starts_with( '(' ) )
    {
        return parseLabel( text );
    }

    return std::unexpected( "error" );
}

} // namespace Hasm::Parser
