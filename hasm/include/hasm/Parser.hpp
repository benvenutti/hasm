#pragma once

#include <hasm/Hasm.hpp>

#include <istream>
#include <optional>
#include <string>

namespace Hasm
{

class Parser
{
public:
    enum class Status
    {
        start_of_file,
        valid_command,
        invalid_command,
        end_of_file
    };

    explicit Parser( std::istream& in );

    bool advance();

    Status                       getStatus() const;
    const std::string&           getCommand() const;
    std::optional< CommandType > getCommandType() const;
    size_t                       getCurrentLineNumber() const;

    std::string symbol() const;
    std::string dest() const;
    std::string comp() const;
    std::string jump() const;

    bool reset();

private:
    bool readNextLine( std::string& str );

    void update( const std::string& newCommand );

    std::istream&                m_input;
    std::string                  m_command{};
    std::optional< CommandType > m_commandType{};
    size_t                       m_lineNumber{ 0u };
    Status                       m_status{ Status::start_of_file };
};

} // namespace Hasm
