#pragma once

#include "Hack.hpp"
#include "Hasm.hpp"
#include "Parser.hpp"
#include "SymbolTable.hpp"

#include <iostream>

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
    Hack::word computeValue( const std::string& symbol );
    bool       isValidValue( Hack::word value ) const;
    void       output( Hack::word word );
    void       displayInvalidACommandMessage();

    std::ostream& m_out;
    Parser        m_parser;
    SymbolTable   m_symbolTable{ Hack::predefined_symbols };
    Hack::word    m_ramAddress{ Hack::init_ram_address };
};

} // namespace Hasm
