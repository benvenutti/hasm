#include <hasm/parser/InstructionParser.hpp>

#include "hasm/language/Grammar.hpp"

#include <charconv>
#include <regex>
#include <unordered_map>

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

std::expected< std::optional< Hasm::Model::Dest >, std::string > parseDest( const std::string_view text )
{
    if ( text.empty() )
    {
        return std::nullopt;
    }

    static const std::unordered_map< std::string_view, Hasm::Model::Dest > table{ { "A", Hasm::Model::Dest::A }, //
                                                                                  { "D", Hasm::Model::Dest::D }, //
                                                                                  { "M", Hasm::Model::Dest::M }, //
                                                                                  { "AD", Hasm::Model::Dest::AD },
                                                                                  { "AM", Hasm::Model::Dest::AM },
                                                                                  { "MD", Hasm::Model::Dest::MD },
                                                                                  { "AMD", Hasm::Model::Dest::AMD } };

    if ( const auto it = table.find( text ); it != table.end() )
    {
        return it->second;
    }

    return std::unexpected( "error" );
}

std::expected< Hasm::Model::Comp, std::string > parseComp( const std::string_view text )
{
    static const std::unordered_map< std::string_view, Hasm::Model::Comp > table{
        { "0", Hasm::Model::Comp::Zero },
        { "1", Hasm::Model::Comp::One },
        { "-1", Hasm::Model::Comp::MinusOne },
        { "D", Hasm::Model::Comp::D },
        { "A", Hasm::Model::Comp::A },
        { "M", Hasm::Model::Comp::M },
        { "!D", Hasm::Model::Comp::NotD },
        { "!A", Hasm::Model::Comp::NotA },
        { "!M", Hasm::Model::Comp::NotM },
        { "-D", Hasm::Model::Comp::NegD },
        { "-A", Hasm::Model::Comp::NegA },
        { "-M", Hasm::Model::Comp::NegM },
        { "D+1", Hasm::Model::Comp::IncrementD },
        { "A+1", Hasm::Model::Comp::IncrementA },
        { "M+1", Hasm::Model::Comp::IncrementM },
        { "D-1", Hasm::Model::Comp::DecrementD },
        { "A-1", Hasm::Model::Comp::DecrementA },
        { "M-1", Hasm::Model::Comp::DecrementM },
        { "D+A", Hasm::Model::Comp::DPlusA },
        { "D+M", Hasm::Model::Comp::DPlusM },
        { "D-A", Hasm::Model::Comp::DMinusA },
        { "D-M", Hasm::Model::Comp::DMinusM },
        { "A-D", Hasm::Model::Comp::AMinusD },
        { "M-D", Hasm::Model::Comp::MMinusD },
        { "D&A", Hasm::Model::Comp::DAndA },
        { "D&M", Hasm::Model::Comp::DAndM },
        { "D|A", Hasm::Model::Comp::DOrA },
        { "D|M", Hasm::Model::Comp::DOrM },
    };

    if ( const auto it = table.find( text ); it != table.end() )
    {
        return it->second;
    }

    return std::unexpected( "error" );
}

std::expected< std::optional< Hasm::Model::Jump >, std::string > parseJump( const std::string_view text )
{
    if ( text.empty() )
    {
        return std::nullopt;
    }

    static const std::unordered_map< std::string_view, Hasm::Model::Jump > table{
        { "JGT", Hasm::Model::Jump::JGT }, //
        { "JEQ", Hasm::Model::Jump::JEQ }, //
        { "JGE", Hasm::Model::Jump::JGE }, //
        { "JLT", Hasm::Model::Jump::JLT }, //
        { "JNE", Hasm::Model::Jump::JNE }, //
        { "JLE", Hasm::Model::Jump::JLE }, //
        { "JMP", Hasm::Model::Jump::JMP },
    };

    if ( const auto it = table.find( text ); it != table.end() )
    {
        return it->second;
    }

    return std::unexpected( "error" );
}

struct ComputeParts
{
    std::string_view dest;
    std::string_view comp;
    std::string_view jump;
};

std::expected< ComputeParts, std::string > splitComputeInstruction( std::string_view text )
{
    const auto equal     = text.find( '=' );
    const auto semicolon = text.find( ';' );

    if ( equal != std::string_view::npos && ( equal == 0 || equal == text.size() - 1 ) )
    {
        return std::unexpected( "error" );
    }

    if ( semicolon != std::string_view::npos && ( semicolon == 0 || semicolon == text.size() - 1 ) )
    {
        return std::unexpected( "error" );
    }

    if ( equal != std::string_view::npos && semicolon != std::string_view::npos && equal > semicolon )
    {
        return std::unexpected( "error" );
    }

    const auto begin = equal == std::string_view::npos ? 0 : equal + 1;

    const auto length = semicolon == std::string_view::npos ? text.size() - begin : semicolon - begin;

    return ComputeParts{ .dest = equal == std::string_view::npos ? std::string_view{} : text.substr( 0, equal ),
                         .comp = text.substr( begin, length ),
                         .jump =
                             semicolon == std::string_view::npos ? std::string_view{} : text.substr( semicolon + 1 ) };
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

std::expected< Hasm::Model::ComputeInstruction, std::string > parseComputeInstruction( std::string_view text )
{
    auto parts = splitComputeInstruction( text );

    if ( !parts )
    {
        return std::unexpected( std::move( parts.error() ) );
    }

    auto dest = parseDest( parts->dest );
    if ( !dest )
    {
        return std::unexpected( std::move( dest.error() ) );
    }

    auto comp = parseComp( parts->comp );
    if ( !comp )
    {
        return std::unexpected( std::move( comp.error() ) );
    }

    auto jump = parseJump( parts->jump );
    if ( !jump )
    {
        return std::unexpected( std::move( jump.error() ) );
    }

    return Hasm::Model::ComputeInstruction{ .dest = *dest, //
                                            .comp = *comp,
                                            .jump = *jump };
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

    return parseComputeInstruction( text );
}

} // namespace Hasm::Parser
