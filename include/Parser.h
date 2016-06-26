#ifndef HASM_PARSER_H_
#define HASM_PARSER_H_

#include <iostream>
#include <string>

#include "Hasm.h"

namespace Hasm {
  class Parser {
    public:
      explicit Parser(std::istream& input);

      bool advance();
      const std::string& getCommand() const;
      HasmCommandType getCommandType() const;
      int getLineNumber() const;

      std::string symbol() const;
      std::string dest() const;
      std::string comp() const;
      std::string jump() const;

      void reset();

    private:
      bool isValidCommand() const;
      bool isACommand() const;
      bool isCCommand() const;
      bool isLCommand() const;

      std::istream& input;
      std::string command = "";
      int lineNumber = 0;
  };
}

#endif
