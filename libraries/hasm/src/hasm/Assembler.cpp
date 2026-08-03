#include <hasm/Assembler.hpp>

#include <hasm/Coder.hpp>

#include <bitset>
#include <cassert>
#include <cctype>
#include <format>
#include <iomanip>
#include <stdexcept>

namespace
{

std::string createMessage( const std::string& instruction, const size_t lineNumber, const std::string& info )
{
    return std::format( R"(line {}: error: "{}" {})", lineNumber, instruction, info );
}

} // namespace

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
            if ( !m_symbolTable.addEntry( m_parser.symbol(), lineCounter ) )
            {
                m_logger( createMessage( m_parser.getInstruction(),
                                         m_parser.getCurrentLineNumber(),
                                         std::format( R"(duplicates symbol "{}")", m_parser.symbol() ) ) );

                return false;
            }
        }
        else
        {
            lineCounter++;
        }
    }

    if ( m_parser.getStatus() == Parser::Parser::Status::invalid_instruction )
    {
        m_logger(
            createMessage( m_parser.getInstruction(), m_parser.getCurrentLineNumber(), "is an invalid command" ) );
    }

    return m_parser.getStatus() == Parser::Parser::Status::end_of_file;
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
    const auto symbol = m_parser.symbol();
    const auto value  = computeValue( symbol );

    if ( value <= Hack::max_loadable_value )
    {
        output( value );

        return true;
    }

    m_logger( createMessage( m_parser.getInstruction(),
                             m_parser.getCurrentLineNumber(),
                             "loads a value greater than an unsigned 15-bit number" ) );

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
        value                                = m_ramAddress++;
        [[maybe_unused]] const auto inserted = m_symbolTable.addEntry( symbol, value );

        // The symbol was just looked up and found to be absent, so insertion must succeed.
        assert( inserted );
    }

    return value;
}

void Assembler::output( const Hack::word word )
{
    m_out << std::bitset< 16 >( word ).to_string() << std::endl;
}

} // namespace Hasm
