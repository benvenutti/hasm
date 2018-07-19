#pragma once

#include "Hack.hpp"

#include <map>
#include <ostream>

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
