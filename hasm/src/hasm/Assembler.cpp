#include <hasm/Assembler.hpp>

#include <hasm/Coder.hpp>
#include <hasm/ErrorMessage.hpp>

#include <bitset>
#include <cctype>
#include <iomanip>
#include <stdexcept>

namespace Hasm
{

Assembler::Assembler( std::istream& in, std::ostream& out, const Logger& logger )
: m_out( out )
, m_parser( in )
, m_logger( logger )
{
    if ( !m_logger )
    {
        throw std::logic_error( "invalid logger" );
    }
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
        if ( m_parser.getInstructionType() == Hack::InstructionType::label )
        {
            m_symbolTable.addEntry( m_parser.symbol(), lineCounter );
        }
        else
        {
            lineCounter++;
        }
    }

    if ( m_parser.getStatus() == Parser::Status::invalid_instruction )
    {
        m_logger( ErrorMessage::invalidInstruction( m_parser.getInstruction(), m_parser.getCurrentLineNumber() ) );
    }

    return m_parser.getStatus() == Parser::Status::end_of_file;
}

bool Assembler::secondPass()
{
    bool ok{ true };

    while ( ok && m_parser.advance() )
    {
        if ( const auto commandType = m_parser.getInstructionType() )
        {
            ok = assembleInstruction( commandType.value() );
        }
        else
        {
            ok = false;
        }
    }

    return ok;
}

bool Assembler::assembleInstruction( const Hack::InstructionType instructionType )
{
    switch ( instructionType )
    {
        case Hack::InstructionType::addressing:
            return assembleAddressingInstruction();
        case Hack::InstructionType::computation:
            return assembleComputationInstruction();
        default:
            return true;
    }
}

bool Assembler::assembleAddressingInstruction()
{
    const auto symbol  = m_parser.symbol();
    const auto value   = computeValue( symbol );

    if ( value <= Hack::max_loadable_value )
    {
        output( value );

        return true;
    }

    m_logger( ErrorMessage::invalidLoadValue( m_parser.getInstruction(), m_parser.getCurrentLineNumber() ) );

    return false;
}

bool Assembler::assembleComputationInstruction()
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

void Assembler::output( const Hack::word word )
{
    m_out << std::bitset< 16 >( word ).to_string() << std::endl;
}

} // namespace Hasm
