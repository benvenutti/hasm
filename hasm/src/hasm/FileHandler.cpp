#include <hasm/FileHandler.hpp>

#include <boost/algorithm/string.hpp>

#include <filesystem>

namespace Hasm
{

std::string FileHandler::changeExtension( const std::string& file, const std::string& newExtension )
{
    std::filesystem::path path{ file };
    path.replace_extension( newExtension );
    const auto pathString = path.string();

    return pathString;
}

bool FileHandler::hasExtension( const std::string& file, const std::string& extension )
{
    const std::filesystem::path path{ file };
    const auto                  isEqual = boost::iequals( path.extension().string(), extension );

    return isEqual;
}

} // namespace Hasm
