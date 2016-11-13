#ifndef HASM_PARSER_HPP
#define HASM_PARSER_HPP

#include <istream>
#include <string>

#include "Hasm.hpp"

namespace Hasm {

class Parser {
  public:
    enum class Status {
        START_OF_FILE,
        VALID_COMMAND,
        INVALID_COMMAND,
        END_OF_FILE
    };

    explicit Parser(std::istream& in);

    bool advance();

    Status getStatus() const;
    const std::string& getCommand() const;
    CommandType getCommandType() const;
    int getCurrentLineNumber() const;

    std::string symbol() const;
    std::string dest() const;
    std::string comp() const;
    std::string jump() const;

    bool reset();

  private:
    bool readNextLine(std::string& str);

    void update(const std::string& newCommand);
    void setCommand(const std::string& newCommand);
    void updateStatus();
    void checkErrors();

    void trim(std::string& str) const;
    void removeComments(std::string& str) const;
    void removeSpaces(std::string& str) const;

    bool isValidCommand() const;
    bool isACommand() const;
    bool isCCommand() const;
    bool isLCommand() const;

    std::istream& input;
    std::string command{""};
    mutable CommandType commandType{CommandType::INVALID};
    int lineNumber{0};
    Status status{Status::START_OF_FILE};
};

} // namespace Hasm

#endif
