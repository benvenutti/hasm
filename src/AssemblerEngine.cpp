#include "AssemblerEngine.hpp"

#include "Assembler.hpp"
#include "AssemblerEngineConfig.hpp"
#include "CommandLineParser.hpp"
#include "FileHandler.hpp"
#include "SymbolTableWriter.hpp"

#include <fstream>
#include <iostream>

namespace Hasm
{

bool AssemblerEngine::run( const EngineConfig& config ) const
{
    if ( !isAsmFile( config.source ) )
    {
        return false;
    }

    std::ifstream inputFile{ config.source };

    if ( !inputFile.good() )
    {
        std::cerr << "error: unable to open input stream" << std::endl;

        return false;
    }

    const std::string outputName{ FileHandler::changeExtension( config.source, ".hack" ) };
    std::ofstream     outputFile{ outputName };

    if ( !outputFile.good() )
    {
        std::cerr << "error: unable to open " << outputName << std::endl;

        return false;
    }

    Assembler hasm{ inputFile, outputFile };
    bool      isOk{ hasm.assemble() };

    if ( config.exportSymbols )
    {
        isOk = exportSymbolTable( config.source, hasm.getSymbolTable() );
    }

    if ( inputFile.is_open() )
    {
        inputFile.close();
    }

    if ( outputFile.is_open() )
    {
        outputFile.close();
    }

    return isOk;
}

bool AssemblerEngine::exportSymbolTable( const std::string& fileName, const SymbolTable& table ) const
{
    const std::string symbolsOutName{ FileHandler::changeExtension( fileName, "sym" ) };
    std::ofstream     symbolsOut{ symbolsOutName };

    if ( !symbolsOut.good() )
    {
        std::cerr << "error: unable to open output stream" << std::endl;

        return false;
    }

    outputSymbolTable( symbolsOut, table );
    symbolsOut.close();

    return true;
}

void AssemblerEngine::outputSymbolTable( std::ostream& out, const SymbolTable& table ) const
{
    SymbolTableWriter tableWriter{ table };
    tableWriter.write( out );
}

bool AssemblerEngine::isAsmFile( const std::string& fileName ) const
{
    if ( !FileHandler::isFile( fileName ) )
    {
        std::cerr << "error: input \"" << fileName << "\"is not a file" << std::endl;

        return false;
    }

    if ( !FileHandler::hasExtension( fileName, ".asm" ) )
    {
        std::cerr << "error: input file must have .asm extension" << std::endl;

        return false;
    }

    return true;
}

} // namespace Hasm
