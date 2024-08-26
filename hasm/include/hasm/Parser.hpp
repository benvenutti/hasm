#pragma once

#include <hasm/Hasm.hpp>

#include <istream>
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

    Status             getStatus() const;
    const std::string& getCommand() const;
    CommandType        getCommandType() const;
    int                getCurrentLineNumber() const;

    std::string symbol() const;
    std::string dest() const;
    std::string comp() const;
    std::string jump() const;

    bool reset();

private:
    bool readNextLine( std::string& str );

    void update( const std::string& newCommand );
    void setCommand( const std::string& newCommand );
    void updateStatus();
    void checkErrors();

    std::istream& m_input;
    std::string   m_command{};
    CommandType   m_commandType{ CommandType::invalid };
    int           m_lineNumber{ 0 };
    Status        m_status{ Status::start_of_file };
};

} // namespace Hasm
