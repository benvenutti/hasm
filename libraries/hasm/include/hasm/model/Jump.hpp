#pragma once

namespace Hasm::Model
{

/// Jump mnemonic of a Hack C-instruction.
enum class Jump
{
    JGT,
    JEQ,
    JGE,
    JLT,
    JNE,
    JLE,
    JMP
};

} // namespace Hasm::Model
