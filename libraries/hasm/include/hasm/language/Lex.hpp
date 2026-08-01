#pragma once

#include <string_view>

namespace Hasm::Language::Lex
{

// Lexical patterns.

inline constexpr std::string_view identifier{ R"(([[:alpha:]]|_|\.|\$|:)(\w|\.|\$|:)*)" };

inline constexpr std::string_view integer{ R"(\d+)" };

// Punctuation.

inline constexpr std::string_view at{ "@" };
inline constexpr std::string_view equal{ "=" };
inline constexpr std::string_view semicolon{ ";" };
inline constexpr std::string_view leftParen{ R"(\()" };
inline constexpr std::string_view rightParen{ R"(\))" };

} // namespace Hasm::Language::Lex
