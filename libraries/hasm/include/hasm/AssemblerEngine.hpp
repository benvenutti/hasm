#pragma once

#include <hasm/Assembler.hpp>
#include <hasm/AssemblerOptions.hpp>

#include <filesystem>
#include <ostream>

namespace Hasm
{

class SymbolTable;

class AssemblerEngine
{
public:
    AssemblerEngine( Assembler::Logger logger );

    bool run( const AssemblerOptions& options ) const;

private:
    const Assembler::Logger m_logger;
};

} // namespace Hasm
