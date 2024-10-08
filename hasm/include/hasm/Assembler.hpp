#pragma once

#include <hasm/Parser.hpp>
#include <hasm/PredefinedSymbols.hpp>
#include <hasm/SymbolTable.hpp>

#include <Hack/Hack.hpp>
#include <Hack/InstructionType.hpp>

#include <functional>
#include <istream>
#include <ostream>
#include <string>

namespace Hasm
{

class Assembler
{
public:
    using Logger = std::function< void( const std::string& message ) >;

    Assembler( std::istream& in, std::ostream& out, const Logger& logger );

    bool               assemble();
    const SymbolTable& getSymbolTable() const;

private:
    bool       firstPass();
    bool       secondPass();
    bool       assembleInstruction( Hack::InstructionType instructionType );
    bool       assembleAddressingInstruction();
    bool       assembleComputationInstruction();
    Hack::word computeValue( const std::string& symbol );
    void       output( Hack::word word );

    std::ostream& m_out;
    Parser        m_parser;
    SymbolTable   m_symbolTable{ predefined_symbols };
    Hack::word    m_ramAddress{ Hack::init_ram_address };
    const Logger& m_logger;
};

} // namespace Hasm
