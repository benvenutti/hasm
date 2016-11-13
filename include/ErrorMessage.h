#ifndef HASM_ERRORMESSAGE_H_
#define HASM_ERRORMESSAGE_H_

#include <string>

namespace Hasm {
namespace ErrorMessage {

std::string invalidCommand(const std::string& cmd, const int lineNumber);
std::string invalidLoadValue(const std::string& cmd, const int lineNumber);

} // namespace ErrorMessage
} // namespace Hasm

#endif