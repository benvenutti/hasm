#pragma once

#include <ostream>
#include <string>

namespace Hasm
{

class EngineConfig;
class SymbolTable;

class AssemblerEngine
{
public:
    AssemblerEngine() = default;

    bool run( const EngineConfig& config ) const;

private:
    bool isAsmFile( const std::string& fileName ) const;
    bool exportSymbolTable( const std::string& fileName, const SymbolTable& table ) const;
    void outputSymbolTable( std::ostream& out, const SymbolTable& table ) const;
};

} // namespace Hasm
