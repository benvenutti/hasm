#pragma once

#include <hasm/Assembler.hpp>
#include <hasm/AssemblerOptions.hpp>

namespace Hasm::AssemblerEngine
{

/// Runs the assembler.
///
/// Returns false for assembly or I/O failures. Throws std::logic_error if logger is empty.
///
[[nodiscard]] bool run( const AssemblerOptions& options, const Assembler::Logger& logger );

} // namespace Hasm::AssemblerEngine
