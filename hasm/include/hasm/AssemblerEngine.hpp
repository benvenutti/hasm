#pragma once

#include <ostream>
#include <string>

namespace Hasm
{

class AssemblerEngineConfig;
class SymbolTable;

class AssemblerEngine
{
public:
    AssemblerEngine() = default;

    bool run( const AssemblerEngineConfig& config ) const;

private:
    bool isAsmFile( const std::string& fileName ) const;
    bool exportSymbolTable( const AssemblerEngineConfig& cfg, const SymbolTable& table ) const;
    void outputSymbolTable( std::ostream& out, const SymbolTable& table ) const;
};

} // namespace Hasm
