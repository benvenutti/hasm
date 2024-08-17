#pragma once

#include <filesystem>

namespace Hasm
{

class AssemblerEngineConfig
{
public:
    AssemblerEngineConfig( std::filesystem::path inputFile, bool exportSymbols )
    : m_inputFile{ std::move( inputFile ) }
    , m_exportSymbols{ exportSymbols }
    {
    }

    [[nodiscard]] const std::filesystem::path& inputFile() const noexcept
    {
        return m_inputFile;
    }

    [[nodiscard]] bool exportSymbols() const noexcept
    {
        return m_exportSymbols;
    }

private:
    const std::filesystem::path m_inputFile;
    const bool                  m_exportSymbols;
};

} // namespace Hasm
