#include "FileHandler.h"

#include <boost/filesystem.hpp>

using Hasm::FileHandler;

std::string FileHandler::changeExtension(const std::string& fileName, const std::string& newExtension) {
  std::string newName(fileName);

  if (newName.rfind(".") != std::string::npos) {
    newName.erase(newName.rfind("."));
  }
  else {
    newName.append(".");
  }

  newName.append(newExtension);

  return newName;
}

bool FileHandler::hasExtension(const std::string& fileName, const std::string& extension) {
  return fileName.rfind(extension) != std::string::npos;
}

bool FileHandler::isFile(const std::string& fileName) {
  boost::filesystem::path path(fileName);

  return boost::filesystem::is_regular_file(path);
}
