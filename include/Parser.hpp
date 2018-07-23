#pragma once

#include "Hasm.hpp"

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

    void trim( std::string& str ) const;
    void removeComments( std::string& str ) const;
    void removeSpaces( std::string& str ) const;

    bool isValidCommand() const;
    bool isACommand() const;
    bool isCCommand() const;
    bool isLCommand() const;

    std::istream&       input;
    std::string         command{ "" };
    mutable CommandType commandType{ CommandType::invalid };
    int                 lineNumber{ 0 };
    Status              status{ Status::start_of_file };
};

} // namespace Hasm
