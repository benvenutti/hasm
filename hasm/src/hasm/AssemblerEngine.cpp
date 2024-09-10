#include <hasm/AssemblerEngine.hpp>

#include <hasm/Assembler.hpp>
#include <hasm/AssemblerEngineConfig.hpp>
#include <hasm/SymbolTableWriter.hpp>

#include <fstream>
#include <iostream>

namespace Hasm
{

bool AssemblerEngine::run( const AssemblerEngineConfig& config ) const
{
    if ( !isAsmFile( config.inputFile() ) )
    {
        return false;
    }

    std::ifstream inputFile{ config.inputFile() };

    if ( !inputFile.good() )
    {
        std::cerr << "error: unable to open input stream" << std::endl;

        return false;
    }

    auto outputPath = config.inputFile();
    outputPath.replace_extension( "hack" );

    std::ofstream outputFile{ outputPath };

    if ( !outputFile.good() )
    {
        std::cerr << "error: unable to open " << outputPath << std::endl;

        return false;
    }

    Assembler hasm{ inputFile, outputFile, []( const auto& message ) { std::cout << message << std::endl; } };
    bool      isOk{ hasm.assemble() };

    if ( config.exportSymbols() )
    {
        isOk = exportSymbolTable( config, hasm.getSymbolTable() );
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

bool AssemblerEngine::exportSymbolTable( const AssemblerEngineConfig& config, const SymbolTable& table ) const
{
    auto outputPath = config.inputFile();
    outputPath.replace_extension( "sym" );

    std::ofstream outStream{ outputPath };

    if ( !outStream.good() )
    {
        std::cerr << "error: unable to open output stream" << std::endl;

        return false;
    }

    outputSymbolTable( outStream, table );
    outStream.close();

    return true;
}

void AssemblerEngine::outputSymbolTable( std::ostream& out, const SymbolTable& table ) const
{
    SymbolTableWriter tableWriter{ table };
    tableWriter.write( out );
}

bool AssemblerEngine::isAsmFile( const std::filesystem::path& path ) const
{
    std::error_code errorCode{};

    if ( !std::filesystem::is_regular_file( path, errorCode ) )
    {
        std::cerr << "error: input \"" << path << "\"is not a file" << std::endl;

        return false;
    }

    if ( path.extension() != ".asm" )
    {
        std::cerr << "error: input file must have .asm extension" << std::endl;

        return false;
    }

    return true;
}

} // namespace Hasm
