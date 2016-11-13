#include "ErrorMessage.hpp"

#include <sstream>

namespace Hasm {

namespace {

std::string message(const std::string& cmd, const int lineNumber, const std::string& info) {
  std::stringstream ss{};
  ss << "line " << lineNumber << ": error: \"" << cmd << "\" " << info;

  return ss.str();
}

} // unnamed namespace

std::string ErrorMessage::invalidCommand(const std::string& cmd, const int lineNumber) {
  return message(cmd, lineNumber, "is an invalid command");
}

std::string ErrorMessage::invalidLoadValue(const std::string& cmd, const int lineNumber) {
  return message(cmd, lineNumber, "loads a value greater than an unsigned 15-bit number");
}

} // namespace Hasm