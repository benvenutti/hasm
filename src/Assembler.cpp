#include "Assembler.hpp"

#include "Coder.hpp"
#include "ErrorMessage.hpp"

#include <bitset>
#include <cctype>
#include <iomanip>

namespace Hasm
{

Assembler::Assembler( std::istream& in, std::ostream& out )
: m_out( out )
, m_parser( in )
{
}

bool Assembler::assemble()
{
    return firstPass() && m_parser.reset() && secondPass();
}

const SymbolTable& Assembler::getSymbolTable() const
{
    return m_symbolTable;
}

bool Assembler::firstPass()
{
    Hack::WORD lineCounter{ 0 };

    while ( m_parser.advance() )
    {
        if ( m_parser.getCommandType() == CommandType::LABEL )
        {
            m_symbolTable.addEntry( m_parser.symbol(), lineCounter );
        }
        else
        {
            lineCounter++;
        }
    }

    return m_parser.getStatus() == Parser::Status::END_OF_FILE;
}

bool Assembler::secondPass()
{
    bool ok{ true };

    while ( ok && m_parser.advance() )
    {
        const auto commandType = m_parser.getCommandType();
        ok                     = assembleCommand( commandType );
    }

    return ok;
}

bool Assembler::assembleCommand( const CommandType commandType )
{
    switch ( commandType )
    {
        case CommandType::ADDRESSING:
            return assembleACommand();
        case CommandType::COMPUTATION:
            return assembleCCommand();
        default:
            return true;
    }
}

bool Assembler::assembleACommand()
{
    const auto symbol  = m_parser.symbol();
    const auto value   = computeValue( symbol );
    const auto isValid = isValidValue( value );

    if ( isValid )
    {
        output( value );
    }
    else
    {
        displayInvalidACommandMessage();
    }

    return isValid;
}

void Assembler::displayInvalidACommandMessage()
{
    const auto cmd        = m_parser.getCommand();
    const auto lineNumber = m_parser.getCurrentLineNumber();
    std::cerr << ErrorMessage::invalidLoadValue( cmd, lineNumber ) << std::endl;
}

bool Assembler::assembleCCommand()
{
    Hack::WORD cc{ 0 };

    cc = Coder::dest( m_parser.dest() ) | Coder::comp( m_parser.comp() ) | Coder::jump( m_parser.jump() )
         | static_cast<Hack::WORD>( 0b1110000000000000 );

    output( cc );

    return true;
}

Hack::WORD Assembler::computeValue( const std::string& symbol )
{
    Hack::WORD value{ 0u };

    if ( std::isdigit( symbol.front() ) != 0 )
    {
        value = static_cast<Hack::WORD>( std::stoi( m_parser.symbol() ) );
    }
    else if ( m_symbolTable.contains( symbol ) )
    {
        value = m_symbolTable.getAddress( symbol ).get();
    }
    else
    {
        value = m_ramAddress++;
        m_symbolTable.addEntry( symbol, value );
    }

    return value;
}

bool Assembler::isValidValue( const Hack::WORD value ) const
{
    return value <= MAX_LOADABLE_VALUE;
}

void Assembler::output( const Hack::WORD word )
{
    m_out << std::bitset<16>( word ).to_string() << std::endl;
}

} // namespace Hasm
