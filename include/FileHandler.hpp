#ifndef HASM_FILEHANDLER_HPP
#define HASM_FILEHANDLER_HPP

#include <string>

namespace Hasm {
namespace FileHandler {

std::string changeExtension(const std::string& file, const std::string& newExtension);
bool hasExtension(const std::string& file, const std::string& extension);
bool isFile(const std::string& file);

} // namespace FileHandler
} // namespace Hasm

#endif
