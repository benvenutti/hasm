#pragma once

#include <filesystem>
#include <variant>

namespace Utilities::CommandLineParser
{

struct Config
{
    std::filesystem::path inputFile;
    bool                  exportSymbols;
};

struct Error
{
};

using Result = std::variant< Config, Error >;

Result parse( int argc, char const* const* argv );

} // namespace Utilities::CommandLineParser
