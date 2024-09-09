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

std::optional< Hasm::CommandType > commandType( const std::string& command )
{
    if ( Hasm::HackCommandParser::isLoadCommand( command ) )
    {
        return Hasm::CommandType::addressing;
    }

    if ( Hasm::HackCommandParser::isLabelCommand( command ) )
    {
        return Hasm::CommandType::label;
    }

    if ( Hasm::HackCommandParser::isComputationCommand( command ) )
    {
        return Hasm::CommandType::computation;
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

const std::string& Parser::getCommand() const
{
    return m_command;
}

std::optional< CommandType > Parser::getCommandType() const
{
    return m_commandType;
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

void Parser::setCommand( std::string command )
{
    m_command     = std::move( command );
    m_commandType = commandType( m_command );
    m_status      = m_commandType.has_value() ? Status::valid_command : Status::invalid_command;
}

bool Parser::advance()
{
    std::string command{};
    while ( readNextLine( command ) )
    {
        removeComment( command );
        removeSpaces( command );

        if ( !command.empty() )
        {
            setCommand( command );

            return m_status == Status::valid_command;
        }
    }

    m_status = Status::end_of_file;

    return false;
}

std::string Parser::symbol() const
{
    if ( getCommandType() == CommandType::addressing )
    {
        return m_command.substr( 1 );
    }

    return m_command.substr( 1, m_command.size() - 2 );
}

std::string Parser::dest() const
{
    // C_COMMAND dest=comp;jump
    if ( m_command.find( '=' ) != std::string::npos )
    {
        return m_command.substr( 0, m_command.find( '=' ) );
    }

    return {};
}

std::string Parser::comp() const
{
    // C_COMMAND dest=comp;jump
    if ( m_command.find( '=' ) == std::string::npos )
    { // dest omitted
        return m_command.substr( 0, m_command.find( ';' ) );
    }

    if ( m_command.find( ';' ) == std::string::npos )
    { // jump omitted
        return m_command.substr( m_command.find( '=' ) + 1 );
    }

    std::string s{ m_command.substr( m_command.find( '=' ) + 1 ) };

    return s.substr( 0, s.find( ';' ) );
}

std::string Parser::jump() const
{
    // C_COMMAND dest=comp;jump
    if ( m_command.find( ';' ) != std::string::npos )
    {
        return m_command.substr( m_command.find( ';' ) + 1 );
    }

    return {};
}

bool Parser::reset()
{
    m_command.clear();
    m_lineNumber = 0u;
    m_status     = Status::start_of_file;
    m_commandType.reset();
    m_input.clear();
    m_input.seekg( std::streampos{ 0 } );

    return m_input.good();
}

} // namespace Hasm
