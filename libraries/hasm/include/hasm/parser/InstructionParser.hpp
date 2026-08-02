#pragma once

#include <hasm/model/Instruction.hpp>

#include <expected>
#include <string>
#include <string_view>

namespace Hasm::Parser
{

using ParseResult = std::expected< Model::Instruction, std::string >;

ParseResult parse( std::string_view text );

} // namespace Hasm::Parser
