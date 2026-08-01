#pragma once

#include <hasm/model/Comp.hpp>
#include <hasm/model/Dest.hpp>
#include <hasm/model/Jump.hpp>

#include <cstdint>
#include <optional>
#include <string>
#include <variant>

namespace Hasm::Model
{

/// Represents a numeric literal used by an A-instruction.
struct Literal
{
    uint16_t value;
};

/// Represents a symbolic reference.
struct Symbol
{
    std::string name;
};

/// Represents an A-instruction.
struct AddressInstruction
{
    std::variant< Literal, Symbol > operand;
};

/// Represents a C-instruction.
struct ComputeInstruction
{
    std::optional< Dest > dest;
    Comp                  comp;
    std::optional< Jump > jump;
};

/// Represents a label declaration.
struct Label
{
    Symbol symbol;
};

/// A Hack assembly instruction.
using Instruction = std::variant< AddressInstruction, ComputeInstruction, Label >;

} // namespace Hasm::Model
