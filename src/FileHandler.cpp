#include "FileHandler.h"

#include <sys/stat.h>

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
  return fileName.rfind(extension) != std::string::npos ? true : false;
}

bool FileHandler::isFile(const std::string& fileName) {
  struct stat buffer;
  stat(fileName.c_str(), &buffer);

  return S_ISREG(buffer.st_mode);
}
