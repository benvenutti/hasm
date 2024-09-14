#include <hasm/AssemblerEngine.hpp>

#include <hasm/AssemblerEngineConfig.hpp>
#include <hasm/SymbolTableWriter.hpp>

#include <format>
#include <fstream>
#include <stdexcept>

namespace Hasm
{

AssemblerEngine::AssemblerEngine( Assembler::Logger logger )
: m_logger{ std::move( logger ) }
{
    if ( !m_logger )
    {
        throw std::logic_error( "invalid logger" );
    }
}

bool AssemblerEngine::run( const AssemblerEngineConfig& config ) const
{
    if ( !isAsmFile( config.inputFile() ) )
    {
        return false;
    }

    std::ifstream inputFile{ config.inputFile() };

    if ( !inputFile.good() )
    {
        m_logger( "error: unable to open input stream" );

        return false;
    }

    auto outputPath = config.inputFile();
    outputPath.replace_extension( "hack" );

    std::ofstream outputFile{ outputPath };

    if ( !outputFile.good() )
    {
        m_logger( std::format( R"(error: unable to open "{}")", outputPath.string() ) );

        return false;
    }

    Assembler hasm{ inputFile, outputFile, m_logger };
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
        m_logger( "error: unable to open output stream" );

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
        m_logger( std::format( R"(error: input "{}" is not a file)", path.string() ) );

        return false;
    }

    if ( path.extension() != ".asm" )
    {
        m_logger( "error: input file must have .asm extension" );

        return false;
    }

    return true;
}

} // namespace Hasm
