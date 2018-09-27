#include "FileHandler.hpp"

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>

namespace Hasm
{

std::string FileHandler::changeExtension( const std::string& file, const std::string& newExtension )
{
    boost::filesystem::path path{ file };
    path.replace_extension( newExtension );
    const auto pathString = path.string();

    return pathString;
}

bool FileHandler::hasExtension( const std::string& file, const std::string& extension )
{
    const boost::filesystem::path path{ file };
    const auto                    isEqual = boost::iequals( path.extension().string(), extension );

    return isEqual;
}

bool FileHandler::isFile( const std::string& file )
{
    const boost::filesystem::path path{ file };
    const auto                    isRegularFile = boost::filesystem::is_regular_file( path );

    return isRegularFile;
}

} // namespace Hasm
