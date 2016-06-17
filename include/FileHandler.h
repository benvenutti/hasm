#ifndef HASM_FILEHANDLER_H_
#define HASM_FILEHANDLER_H_

#include <string>

namespace Hasm {
  class FileHandler {
    public:
      static std::string changeExtension(const std::string& fileName, const std::string& newExtension);
      static bool hasExtension(const std::string& fileName, const std::string& extension);
      static bool isFile(const std::string& fileName);
  };
};

#endif
