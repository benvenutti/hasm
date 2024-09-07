#pragma once

#include <filesystem>
#include <string>
#include <variant>

namespace Utilities::CommandLineParser
{

struct Config
{
    std::filesystem::path inputFile;
    bool                  exportSymbols;
};

struct RequestToPrintHelp
{
    std::string message;
};

struct Error
{
};

using Result = std::variant< Config, RequestToPrintHelp, Error >;

Result parse( int argc, char const* const* argv );

} // namespace Utilities::CommandLineParser
