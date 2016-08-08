#include "Parser.h"

#include <algorithm>

using Hasm::Parser;

Parser::Parser(std::istream& input)
    : input(input) {
}

const std::string& Parser::getCommand() const {
  return command;
}

void removeSpaces(std::string& str) {
  str.erase(
      std::remove_if(
          str.begin(),
          str.end(),
          [](char c) { return (c == '\r' || c == '\t' || c == ' ' || c == '\n'); }
      ), str.end()
  );
}

void removeComments(std::string& str) {
  size_t pos = str.find("//");

  if (pos != std::string::npos) {
    str.erase(pos, str.size());
    str.find("//");
  }
}

bool Parser::advance() {
  while (getline(input, command)) {
    lineNumber++;

    removeSpaces(command);
    removeComments(command);

    if (!command.empty()) {
      if (isValidCommand()) {
        return true;
      }
      else {
        std::cerr << "error at line " << lineNumber << std::endl;

        break;
      }
    }
  }

  return false;
}

Hasm::HasmCommandType Parser::getCommandType() const {
  if (command.front() == '@') {
    return Hasm::HasmCommandType::A_COMMAND;
  }

  if (command.front() == '(') {
    return Hasm::HasmCommandType::L_COMMAND;
  }

  return Hasm::HasmCommandType::C_COMMAND;
}

std::string Parser::symbol() const {
  if (getCommandType() == Hasm::HasmCommandType::A_COMMAND) {
    return command.substr(1);
  }

  return command.substr(1, command.size() - 2);
}

std::string Parser::dest() const {
  // C_COMMAND dest=comp;jump
  if (command.find('=') != std::string::npos) {
    return command.substr(0, command.find('='));
  }

  return "";
}

std::string Parser::comp() const {
  // C_COMMAND dest=comp;jump
  if (command.find('=') == std::string::npos) { // dest omitted
    return command.substr(0, command.find(';'));
  }

  if (command.find(';') == std::string::npos) { // jump omitted
    return command.substr(command.find('=') + 1);
  }

  std::string s = command.substr(command.find('=') + 1);

  return s.substr(0, s.find(';'));
}

std::string Parser::jump() const {
  // C_COMMAND dest=comp;jump
  if (command.find(';') != std::string::npos) {
    return command.substr(command.find(';') + 1);
  }

  return "";
}

void Parser::reset() {
  input.clear();
  input.seekg(0);
  command = std::string("");
  lineNumber = 0;
}

bool Parser::isValidCommand() const {
  return isACommand() || isLCommand() || isCCommand();
}

bool Parser::isACommand() const {
  return (command.front() == '@') && (command.size() > 1);
}

bool Parser::isCCommand() const {
  // TODO
  return true;
}

bool Parser::isLCommand() const {
  return (command.front() == '(') && (command.back() == ')') && (command.size() > 2);
}
