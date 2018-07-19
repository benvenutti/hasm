#ifndef HASM_SYMBOLTABLEWRITER_HPP
#define HASM_SYMBOLTABLEWRITER_HPP

#include <map>
#include <ostream>

#include "Hack.hpp"

namespace Hasm
{

class SymbolTable;

class SymbolTableWriter
{
public:
    SymbolTableWriter( const SymbolTable& symbolTable );

    void write( std::ostream& out );

private:
    std::multimap<Hack::WORD, std::string> symbolMap;
};

} // namespace Hasm

#endif
