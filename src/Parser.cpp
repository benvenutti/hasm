#include "Parser.hpp"

#include <algorithm>
#include <cctype>

#include "ErrorMessage.hpp"
#include "HackCommandParser.hpp"

using Hasm::Parser;

Parser::Parser(std::istream& input)
    : input(input) {}

Parser::Status Parser::getStatus() const {
  return status;
}

const std::string& Parser::getCommand() const {
  return command;
}

Hasm::CommandType Parser::getCommandType() const {
  return commandType;
}

int Parser::getCurrentLineNumber() const {
  return lineNumber;
}

void Parser::trim(std::string& str) const {
  removeComments(str);
  removeSpaces(str);
}

void Parser::removeSpaces(std::string& str) const {
  str.erase(
    std::remove_if(
      str.begin(),
      str.end(),
      [](char c) { return std::isspace(c); }
    ), str.end()
  );
}

void Parser::removeComments(std::string& str) const {
  const auto pos = str.find("//");

  if (pos != std::string::npos) {
    str.erase(pos, str.size());
  }
}

bool Parser::readNextLine(std::string &str) {
  if (getline(input, str)) {
    lineNumber++;

    return true;
  }

  return false;
}

void Parser::update(const std::string& newCommand) {
  setCommand(newCommand);
  updateStatus();
  checkErrors();
}

void Parser::setCommand(const std::string &newCommand) {
  command = newCommand;
}

void Parser::updateStatus() {
  status = isValidCommand() ? Status::VALID_COMMAND : Status::INVALID_COMMAND;
}

void Parser::checkErrors() {
  if (status == Status::INVALID_COMMAND) {
    std::cerr << Hasm::ErrorMessage::invalidCommand(command, lineNumber) << std::endl;
  }
}

bool Parser::advance() {
  std::string line{""};
  while (readNextLine(line)) {
    trim(line);

    if (!line.empty()) {
      update(line);

      return status == Status::VALID_COMMAND;
    }
  }

  status = Status::END_OF_FILE;

  return false;
}

std::string Parser::symbol() const {
  if (getCommandType() == Hasm::CommandType::ADDRESSING) {
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

bool Parser::reset() {
  command = std::string("");
  lineNumber = 0;
  status = Status::START_OF_FILE;
  commandType = CommandType::INVALID;
  input.clear();
  input.seekg(std::streampos(0));

  return input.good();
}

bool Parser::isValidCommand() const {
  bool isValid = true;

  if (isACommand()) {
    commandType = Hasm::CommandType::ADDRESSING;
  }
  else if (isLCommand()) {
    commandType = Hasm::CommandType::LABEL;
  }
  else if (isCCommand()) {
    commandType = Hasm::CommandType::COMPUTATION;
  }
  else {
    commandType = Hasm::CommandType::INVALID;
    isValid = false;
  }

  return isValid;
}

bool Parser::isACommand() const {
  return Hasm::HackCommandParser::isLoadCommand(command);
}

bool Parser::isCCommand() const {
  return Hasm::HackCommandParser::isComputationCommand(command);
}

bool Parser::isLCommand() const {
  return Hasm::HackCommandParser::isLabelCommand(command);
}
