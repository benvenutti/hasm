#pragma once

#include <string>
#include <utility>

namespace Hasm
{

class AssemblerEngineConfig
{
public:
    AssemblerEngineConfig( const bool isValid, const bool exportSymbols, const std::string inputName )
    : m_isValid{ isValid }
    , m_exportSymbols{ exportSymbols }
    , m_inputName{ std::move( inputName ) }
    {
    }

    bool isValid() const noexcept
    {
        return m_isValid;
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
    const bool        m_isValid;
    const bool        m_exportSymbols;
    const std::string m_inputName;
};

} // namespace Hasm
