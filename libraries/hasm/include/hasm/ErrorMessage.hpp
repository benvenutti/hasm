#pragma once

#include <string>

namespace Hasm::ErrorMessage
{

[[nodiscard]] std::string invalidInstruction( const std::string& instruction, size_t lineNumber );

[[nodiscard]] std::string invalidLoadValue( const std::string& instruction, size_t lineNumber );

[[nodiscard]] std::string symbolAlreadyRegistered( const std::string& instruction,
                                                   size_t             lineNumber,
                                                   const std::string& symbol );

} // namespace Hasm::ErrorMessage
