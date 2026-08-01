#pragma once

namespace Hasm::Model
{

/// Destination mnemonic of a Hack C-instruction.
enum class Dest
{
    M,
    D,
    MD,
    A,
    AM,
    AD,
    AMD
};

} // namespace Hasm::Model
