#include "FileHandler.h"

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>

using Hasm::FileHandler;

std::string FileHandler::changeExtension(const std::string& fileName, const std::string& newExtension) {
  boost::filesystem::path path(fileName);
  path.replace_extension(newExtension);

  return path.string();
}

bool FileHandler::hasExtension(const std::string& fileName, const std::string& extension) {
  boost::filesystem::path path(fileName);

  return boost::iequals(path.extension().string(), extension);
}

bool FileHandler::isFile(const std::string& fileName) {
  boost::filesystem::path path(fileName);

  return boost::filesystem::is_regular_file(path);
}
