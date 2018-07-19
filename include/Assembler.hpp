#pragma once

#include <iostream>

#include "Hack.hpp"
#include "Hasm.hpp"
#include "Parser.hpp"
#include "SymbolTable.hpp"

namespace Hasm
{

class Assembler
{
public:
    Assembler( std::istream& in, std::ostream& out );

    bool               assemble();
    const SymbolTable& getSymbolTable() const;

private:
    bool       firstPass();
    bool       secondPass();
    bool       assembleCommand( CommandType commandType );
    bool       assembleACommand();
    bool       assembleCCommand();
    Hack::WORD computeValue( const std::string& symbol );
    bool       isValidValue( Hack::WORD value ) const;
    void       output( Hack::WORD word );
    void       displayInvalidACommandMessage();

    std::ostream& m_out;
    Parser        m_parser;
    SymbolTable   m_symbolTable{ Hack::PREDEFINED_SYMBOLS };
    Hack::WORD    m_ramAddress{ Hack::INIT_RAM_ADDRESS };
};

} // namespace Hasm
