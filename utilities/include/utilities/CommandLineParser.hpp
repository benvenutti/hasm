#pragma once

#include <filesystem>
#include <optional>

namespace Utilities::CommandLineParser
{

struct Config
{
    std::filesystem::path inputFile;
    bool                  exportSymbols;
};

std::optional< Config > parse( int argc, char const* const* argv );

} // namespace Utilities::CommandLineParser
