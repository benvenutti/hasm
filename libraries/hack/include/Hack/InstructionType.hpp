#pragma once

namespace Hack
{

enum class InstructionType
{
    addressing,  /// A-Instruction
    computation, /// C-Instruction
    label        /// L-Instruction
};

} // namespace Hack
