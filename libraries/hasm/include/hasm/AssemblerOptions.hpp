#pragma once

#include <filesystem>

namespace Hasm
{

class AssemblerOptions
{
public:
    AssemblerOptions( std::filesystem::path inputFile, std::filesystem::path outputFile, const bool exportSymbols )
    : m_inputFile{ std::move( inputFile ) }
    , m_outputFile{ std::move( outputFile ) }
    , m_exportSymbols{ exportSymbols }
    {
    }

    [[nodiscard]] const std::filesystem::path& inputFile() const noexcept
    {
        return m_inputFile;
    }

    [[nodiscard]] const std::filesystem::path& outputFile() const noexcept
    {
        return m_outputFile;
    }

    [[nodiscard]] bool exportSymbols() const noexcept
    {
        return m_exportSymbols;
    }

private:
    const std::filesystem::path m_inputFile;
    const std::filesystem::path m_outputFile;
    const bool                  m_exportSymbols;
};

} // namespace Hasm
