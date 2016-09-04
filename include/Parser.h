#ifndef HASM_PARSER_H_
#define HASM_PARSER_H_

#include <iostream>
#include <string>

#include "Hasm.h"

namespace Hasm {
  class Parser {
    public:
      enum class Status {
        START_OF_FILE,
        VALID_COMMAND,
        INVALID_COMMAND,
        END_OF_FILE
      };

      explicit Parser(std::istream& input);

      bool advance();
      Status getStatus() const;
      const std::string& getCommand() const;
      CommandType getCommandType() const;

      std::string symbol() const;
      std::string dest() const;
      std::string comp() const;
      std::string jump() const;

      void reset();

    private:
      bool readNextLine(std::string& str);

      void trim(std::string& str) const;
      void removeComments(std::string& str) const;
      void removeSpaces(std::string& str) const;

      bool isValidCommand() const;
      bool isACommand() const;
      bool isCCommand() const;
      bool isLCommand() const;

      std::istream& input;
      std::string command = "";
      int lineNumber = 0;
      Status status = Status::START_OF_FILE;
  };
}

#endif
