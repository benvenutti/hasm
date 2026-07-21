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

[[nodiscard]] bool isValidOutputFile( const std::filesystem::path& path, const Assembler::Logger& logger )
{
    if ( path.extension() != ".hack" )
    {
        logger( "error: output file must have .hack extension" );
        return false;
    }

    return true;
}

[[nodiscard]] bool validateOptions( const AssemblerOptions& options, const Assembler::Logger& logger )
{
    return options.inputFile() != options.outputFile() && isValidInputFile( options.inputFile(), logger )
           && isValidOutputFile( options.outputFile(), logger );
}

[[nodiscard]] bool exportSymbolTable( std::filesystem::path    outputPath,
                                      const SymbolTable&       table,
                                      const Assembler::Logger& logger )
{
    outputPath.replace_extension( ".sym" );

    std::ofstream outStream{ outputPath };

    if ( !outStream )
    {
        logger( std::format( R"(error: unable to open output stream "{}")", outputPath.string() ) );
        return false;
    }

    SymbolTableWriter tableWriter{ table };
    tableWriter.write( outStream );

    return true;
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

    if ( !inputFile )
    {
        m_logger( std::format( R"(error: unable to open input stream "{}")", options.inputFile().string() ) );
        return false;
    }

    std::ofstream outputFile{ options.outputFile() };

    if ( !outputFile )
    {
        m_logger( std::format( R"(error: unable to open output stream "{}")", options.outputFile().string() ) );
        return false;
    }

    Assembler assembler{ inputFile, outputFile, m_logger };

    bool success = assembler.assemble();

    if ( success && options.exportSymbols() )
    {
        success = exportSymbolTable( options.outputFile(), assembler.getSymbolTable(), m_logger );
    }

    return success;
}

} // namespace Hasm
