#pragma once

#include <string>
#include <utility>

namespace Hasm
{

class AssemblerEngineConfig
{
public:
    AssemblerEngineConfig( const bool exportSymbols, const std::string inputName )
    : m_exportSymbols{ exportSymbols }
    , m_inputName{ std::move( inputName ) }
    {
    }

    bool exportSymbols() const noexcept
    {
        return m_exportSymbols;
    }

    const std::string& inputName() const
    {
        return m_inputName;
    }

private:
    const bool        m_exportSymbols;
    const std::string m_inputName;
};

} // namespace Hasm
