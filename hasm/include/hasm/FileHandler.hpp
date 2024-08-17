#pragma once

#include <string>

namespace Hasm
{
namespace FileHandler
{

std::string changeExtension( const std::string& file, const std::string& newExtension );
bool        hasExtension( const std::string& file, const std::string& extension );

} // namespace FileHandler
} // namespace Hasm
