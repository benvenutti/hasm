#include "FileHandler.h"

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>

namespace Hasm {

std::string FileHandler::changeExtension(
    const std::string& file,
    const std::string& newExtension
) {
  boost::filesystem::path path{file};
  path.replace_extension(newExtension);

  return path.string();
}

bool FileHandler::hasExtension(
    const std::string& file,
    const std::string& extension
) {
  const boost::filesystem::path path{file};

  return boost::iequals(path.extension().string(), extension);
}

bool FileHandler::isFile(const std::string& file) {
  const boost::filesystem::path path{file};

  return boost::filesystem::is_regular_file(path);
}

} // namespace Hasm