#include "FileHandler.hpp"

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>

namespace Hasm
{

std::string FileHandler::changeExtension( const std::string& file, const std::string& newExtension )
{
    return boost::filesystem::path{ file }.replace_extension( newExtension ).string();
}

bool FileHandler::hasExtension( const std::string& file, const std::string& extension )
{
    return boost::iequals( boost::filesystem::path{ file }.extension().string(), extension );
}

bool FileHandler::isFile( const std::string& file )
{
    return boost::filesystem::is_regular_file( boost::filesystem::path{ file } );
}

} // namespace Hasm
