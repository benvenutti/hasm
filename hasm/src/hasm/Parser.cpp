#include <hasm/Parser.hpp>

#include <hasm/ErrorMessage.hpp>
#include <hasm/HackCommandParser.hpp>
#include <hasm/HackLex.hpp>

#include <algorithm>
#include <cctype>
#include <ranges>

namespace
{

void removeSpaces( std::string& str )
{
    const auto range = std::ranges::remove_if( str, []( const auto c ) { return std::isspace( c ); } );
    str.erase( range.begin(), range.end() );
}

void removeComment( std::string& str )
{
    const auto pos = str.find( Hasm::Hack::Lex::line_comment );
    if ( pos != std::string::npos )
    {
        str.erase( pos, str.size() );
    }
}

std::optional< Hack::InstructionType > instructionType( const std::string& instruction )
{
    if ( Hasm::HackCommandParser::isLoadCommand( instruction ) )
    {
        return Hack::InstructionType::addressing;
    }

    if ( Hasm::HackCommandParser::isLabelCommand( instruction ) )
    {
        return Hack::InstructionType::label;
    }

    if ( Hasm::HackCommandParser::isComputationCommand( instruction ) )
    {
        return Hack::InstructionType::computation;
    }

    return std::nullopt;
}

} // namespace

namespace Hasm
{

Parser::Parser( std::istream& in )
: m_input( in )
{
}

Parser::Status Parser::getStatus() const
{
    return m_status;
}

const std::string& Parser::getInstruction() const
{
    return m_instruction;
}

// TODO: fix the need to ::Hack
std::optional< ::Hack::InstructionType > Parser::getInstructionType() const
{
    return m_instructionType;
}

size_t Parser::getCurrentLineNumber() const
{
    return m_lineNumber;
}

bool Parser::readNextLine( std::string& str )
{
    bool hasRead{ false };

    if ( getline( m_input, str ) )
    {
        m_lineNumber++;
        hasRead = true;
    }

    return hasRead;
}

void Parser::setInstruction( std::string instruction )
{
    m_instruction     = std::move( instruction );
    m_instructionType = instructionType( m_instruction );
    m_status          = m_instructionType.has_value() ? Status::valid_instruction : Status::invalid_instruction;
}

bool Parser::advance()
{
    std::string instruction{};
    while ( readNextLine( instruction ) )
    {
        removeComment( instruction );
        removeSpaces( instruction );

        if ( !instruction.empty() )
        {
            setInstruction( instruction );

            return m_status == Status::valid_instruction;
        }
    }

    m_status = Status::end_of_file;

    return false;
}

std::string Parser::symbol() const
{
    // TODO: fix the need to ::Hack
    if ( getInstructionType() == ::Hack::InstructionType::addressing )
    {
        return m_instruction.substr( 1 );
    }

    return m_instruction.substr( 1, m_instruction.size() - 2 );
}

std::string Parser::dest() const
{
    // C_COMMAND dest=comp;jump
    if ( m_instruction.find( '=' ) != std::string::npos )
    {
        return m_instruction.substr( 0, m_instruction.find( '=' ) );
    }

    return {};
}

std::string Parser::comp() const
{
    // C_COMMAND dest=comp;jump
    if ( m_instruction.find( '=' ) == std::string::npos )
    {
        // dest omitted
        return m_instruction.substr( 0, m_instruction.find( ';' ) );
    }

    if ( m_instruction.find( ';' ) == std::string::npos )
    {
        // jump omitted
        return m_instruction.substr( m_instruction.find( '=' ) + 1 );
    }

    std::string s{ m_instruction.substr( m_instruction.find( '=' ) + 1 ) };

    return s.substr( 0, s.find( ';' ) );
}

std::string Parser::jump() const
{
    // C_COMMAND dest=comp;jump
    if ( m_instruction.find( ';' ) != std::string::npos )
    {
        return m_instruction.substr( m_instruction.find( ';' ) + 1 );
    }

    return {};
}

bool Parser::reset()
{
    m_instruction.clear();
    m_lineNumber = 0u;
    m_status     = Status::start_of_file;
    m_instructionType.reset();
    m_input.clear();
    m_input.seekg( std::streampos{ 0 } );

    return m_input.good();
}

} // namespace Hasm
