#include <hasm/Parser.hpp>

#include <hasm/ErrorMessage.hpp>
#include <hasm/HackCommandParser.hpp>
#include <hasm/HackLex.hpp>

#include <algorithm>
#include <cctype>
#include <iostream>
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

} // namespace

namespace Hasm
{

Parser::Parser( std::istream& in )
: input( in )
{
}

Parser::Status Parser::getStatus() const
{
    return status;
}

const std::string& Parser::getCommand() const
{
    return command;
}

CommandType Parser::getCommandType() const
{
    return commandType;
}

int Parser::getCurrentLineNumber() const
{
    return lineNumber;
}

bool Parser::readNextLine( std::string& str )
{
    bool hasRead{ false };

    if ( getline( input, str ) )
    {
        lineNumber++;
        hasRead = true;
    }

    return hasRead;
}

void Parser::update( const std::string& newCommand )
{
    setCommand( newCommand );
    updateStatus();
    checkErrors();
}

void Parser::setCommand( const std::string& newCommand )
{
    command = newCommand;
}

void Parser::updateStatus()
{
    status = isValidCommand() ? Status::valid_command : Status::invalid_command;
}

void Parser::checkErrors()
{
    if ( status == Status::invalid_command )
    {
        std::cerr << ErrorMessage::invalidCommand( command, lineNumber ) << std::endl;
    }
}

bool Parser::advance()
{
    std::string line{ "" };
    while ( readNextLine( line ) )
    {
        removeComment( line );
        removeSpaces( line );

        if ( !line.empty() )
        {
            update( line );

            return status == Status::valid_command;
        }
    }

    status = Status::end_of_file;

    return false;
}

std::string Parser::symbol() const
{
    if ( getCommandType() == CommandType::addressing )
    {
        return command.substr( 1 );
    }

    return command.substr( 1, command.size() - 2 );
}

std::string Parser::dest() const
{
    // C_COMMAND dest=comp;jump
    if ( command.find( '=' ) != std::string::npos )
    {
        return command.substr( 0, command.find( '=' ) );
    }

    return "";
}

std::string Parser::comp() const
{
    // C_COMMAND dest=comp;jump
    if ( command.find( '=' ) == std::string::npos )
    { // dest omitted
        return command.substr( 0, command.find( ';' ) );
    }

    if ( command.find( ';' ) == std::string::npos )
    { // jump omitted
        return command.substr( command.find( '=' ) + 1 );
    }

    std::string s{ command.substr( command.find( '=' ) + 1 ) };

    return s.substr( 0, s.find( ';' ) );
}

std::string Parser::jump() const
{
    // C_COMMAND dest=comp;jump
    if ( command.find( ';' ) != std::string::npos )
    {
        return command.substr( command.find( ';' ) + 1 );
    }

    return "";
}

bool Parser::reset()
{
    command     = std::string{ "" };
    lineNumber  = 0;
    status      = Status::start_of_file;
    commandType = CommandType::invalid;
    input.clear();
    input.seekg( std::streampos{ 0 } );

    return input.good();
}

bool Parser::isValidCommand() const
{
    bool isValid{ true };

    if ( isACommand() )
    {
        commandType = CommandType::addressing;
    }
    else if ( isLCommand() )
    {
        commandType = CommandType::label;
    }
    else if ( isCCommand() )
    {
        commandType = CommandType::computation;
    }
    else
    {
        commandType = CommandType::invalid;
        isValid     = false;
    }

    return isValid;
}

bool Parser::isACommand() const
{
    return HackCommandParser::isLoadCommand( command );
}

bool Parser::isCCommand() const
{
    return HackCommandParser::isComputationCommand( command );
}

bool Parser::isLCommand() const
{
    return HackCommandParser::isLabelCommand( command );
}

} // namespace Hasm
