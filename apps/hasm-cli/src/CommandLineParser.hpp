#pragma once

#include <filesystem>
#include <optional>
#include <string>
#include <variant>

namespace CommandLineParser
{

struct ParsedArguments
{
    std::filesystem::path                  inputFile;
    std::optional< std::filesystem::path > outputFile;
    bool                                   exportSymbols = false;
};

struct RequestToPrintHelp
{
    std::string message;
};

struct RequestToPrintVersion
{
};

struct Error
{
    std::string message;
};

using Result = std::variant< ParsedArguments, RequestToPrintHelp, RequestToPrintVersion, Error >;

[[nodiscard]] Result parse( int argc, char const* const* argv );

} // namespace CommandLineParser
