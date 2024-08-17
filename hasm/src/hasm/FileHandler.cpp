#include <hasm/FileHandler.hpp>

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

} // namespace Hasm
