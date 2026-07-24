#include <hasm/AssemblerEngine.hpp>

#include <hasm/SymbolListingWriter.hpp>

#include <format>
#include <fstream>
#include <stdexcept>

namespace Hasm
{

namespace
{

void validateLogger( const Assembler::Logger& logger )
{
    if ( !logger )
    {
        throw std::logic_error( "invalid logger" );
    }
}

[[nodiscard]] bool validateInputFile( const std::filesystem::path& path, const Assembler::Logger& logger )
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

[[nodiscard]] bool validateOutputFile( const std::filesystem::path& path, const Assembler::Logger& logger )
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
    if ( options.inputFile() == options.outputFile() )
    {
        logger( "error: input and output files must be different" );
        return false;
    }

    return validateInputFile( options.inputFile(), logger ) && validateOutputFile( options.outputFile(), logger );
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

    SymbolListingWriter::write( outStream, table );

    return true;
}

} // namespace

bool AssemblerEngine::run( const AssemblerOptions& options, const Assembler::Logger& logger )
{
    validateLogger( logger );

    if ( !validateOptions( options, logger ) )
    {
        return false;
    }

    std::ifstream inputFile{ options.inputFile() };

    if ( !inputFile )
    {
        logger( std::format( R"(error: unable to open input stream "{}")", options.inputFile().string() ) );
        return false;
    }

    std::ofstream outputFile{ options.outputFile() };

    if ( !outputFile )
    {
        logger( std::format( R"(error: unable to open output stream "{}")", options.outputFile().string() ) );
        return false;
    }

    Assembler assembler{ inputFile, outputFile, logger };

    bool success = assembler.assemble();

    if ( success && options.exportSymbols() )
    {
        success = exportSymbolTable( options.outputFile(), assembler.getSymbolTable(), logger );
    }

    return success;
}

} // namespace Hasm
