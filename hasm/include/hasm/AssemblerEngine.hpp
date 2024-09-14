#pragma once

#include <hasm/Assembler.hpp>

#include <filesystem>
#include <ostream>

namespace Hasm
{

class AssemblerEngineConfig;
class SymbolTable;

class AssemblerEngine
{
public:
    AssemblerEngine( Assembler::Logger logger );

    bool run( const AssemblerEngineConfig& config ) const;

private:
    bool isAsmFile( const std::filesystem::path& path ) const;
    bool exportSymbolTable( const AssemblerEngineConfig& cfg, const SymbolTable& table ) const;
    void outputSymbolTable( std::ostream& out, const SymbolTable& table ) const;

    const Assembler::Logger m_logger;
};

} // namespace Hasm
