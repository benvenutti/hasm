#pragma once

#include "Hack.hpp"
#include "Hasm.hpp"
#include "Parser.hpp"
#include "SymbolTable.hpp"

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

    Assembler( std::istream& in, std::ostream& out, const Logger& logger = {} );

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
    const Logger& m_logger;
};

} // namespace Hasm
