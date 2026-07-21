#include <hasm/AssemblerEngine.hpp>

#include <hasm/SymbolTableWriter.hpp>

#include <format>
#include <fstream>
#include <stdexcept>

namespace Hasm
{

namespace
{

[[nodiscard]] bool isValidInputFile( const std::filesystem::path& path, const Assembler::Logger& logger )
{
    if ( std::error_code errorCode; !std::filesystem::is_regular_file( path, errorCode ) )
    {
        logger( std::format( R"(error: input "{}" is not a file)", path.string() ) );
        return false;
    }

    if ( path.extension() != ".asm" )
    {
        logger( "error: input file must have .asm extension" );
        return false;
    }

    return true;
}

[[nodiscard]] bool validateOptions( const AssemblerOptions& options, const Assembler::Logger& logger )
{
    return isValidInputFile( options.inputFile(), logger );
}

} // namespace

AssemblerEngine::AssemblerEngine( Assembler::Logger logger )
: m_logger{ std::move( logger ) }
{
    if ( !m_logger )
    {
        throw std::logic_error( "invalid logger" );
    }
}

bool AssemblerEngine::run( const AssemblerOptions& options ) const
{
    if ( !validateOptions( options, m_logger ) )
    {
        return false;
    }

    std::ifstream inputFile{ options.inputFile() };

    if ( !inputFile.good() )
    {
        m_logger( "error: unable to open input stream" );

        return false;
    }

    auto outputPath = options.inputFile();
    outputPath.replace_extension( "hack" );

    std::ofstream outputFile{ outputPath };

    if ( !outputFile.good() )
    {
        m_logger( std::format( R"(error: unable to open "{}")", outputPath.string() ) );

        return false;
    }

    Assembler hasm{ inputFile, outputFile, m_logger };
    bool      isOk{ hasm.assemble() };

    if ( options.exportSymbols() )
    {
        isOk = exportSymbolTable( options, hasm.getSymbolTable() );
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

bool AssemblerEngine::exportSymbolTable( const AssemblerOptions& options, const SymbolTable& table ) const
{
    auto outputPath = options.inputFile();
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

} // namespace Hasm
