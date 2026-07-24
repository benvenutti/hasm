#pragma once

#include <hasm/SymbolTable.hpp>

#include <ostream>

namespace Hasm::SymbolListingWriter
{

void write( std::ostream& out, const SymbolTable& symbolTable );

} // namespace Hasm::SymbolListingWriter
