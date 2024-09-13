#include <hasm/Assembler.hpp>

#include <hasm/Coder.hpp>
#include <hasm/ErrorMessage.hpp>

#include <bitset>
#include <cctype>
#include <iomanip>

namespace Hasm
{

Assembler::Assembler( std::istream& in, std::ostream& out, const Logger& logger )
: m_out( out )
, m_parser( in )
, m_logger( logger )
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
    Hack::word lineCounter{ 0_w };

    while ( m_parser.advance() )
    {
        if ( m_parser.getCommandType() == Hack::CommandType::label )
        {
            m_symbolTable.addEntry( m_parser.symbol(), lineCounter );
        }
        else
        {
            lineCounter++;
        }
    }

    return m_parser.getStatus() == Parser::Status::end_of_file;
}

bool Assembler::secondPass()
{
    bool ok{ true };

    while ( ok && m_parser.advance() )
    {
        if ( const auto commandType = m_parser.getCommandType() )
        {
            ok = assembleCommand( commandType.value() );
        }
        else
        {
            ok = false;
        }
    }

    return ok;
}

bool Assembler::assembleCommand( const Hack::CommandType commandType )
{
    switch ( commandType )
    {
        case Hack::CommandType::addressing:
            return assembleACommand();
        case Hack::CommandType::computation:
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

    m_logger( ErrorMessage::invalidLoadValue( cmd, lineNumber ) );
}

bool Assembler::assembleCCommand()
{
    Hack::word cc{ 0_w };

    cc = Coder::dest( m_parser.dest() ) | Coder::comp( m_parser.comp() ) | Coder::jump( m_parser.jump() )
         | static_cast< Hack::word >( 0b1110000000000000 );

    output( cc );

    return true;
}

Hack::word Assembler::computeValue( const std::string& symbol )
{
    Hack::word value{ 0_w };

    if ( std::isdigit( symbol.front() ) != 0 )
    {
        value = static_cast< Hack::word >( std::stoi( m_parser.symbol() ) );
    }
    else if ( m_symbolTable.contains( symbol ) )
    {
        value = m_symbolTable.getAddress( symbol ).value();
    }
    else
    {
        value = m_ramAddress++;
        m_symbolTable.addEntry( symbol, value );
    }

    return value;
}

bool Assembler::isValidValue( const Hack::word value ) const
{
    return value <= Hack::max_loadable_value;
}

void Assembler::output( const Hack::word word )
{
    m_out << std::bitset< 16 >( word ).to_string() << std::endl;
}

} // namespace Hasm
