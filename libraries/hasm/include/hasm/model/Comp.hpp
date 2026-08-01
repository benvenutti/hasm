#pragma once

namespace Hasm::Model
{

/// Computation mnemonic of a Hack C-instruction.
enum class Comp
{
    Zero,
    One,
    MinusOne,

    D,
    A,
    M,

    NotD,
    NotA,
    NotM,

    NegD,
    NegA,
    NegM,

    IncrementD,
    IncrementA,
    IncrementM,

    DecrementD,
    DecrementA,
    DecrementM,

    DPlusA,
    DPlusM,

    DMinusA,
    DMinusM,

    AMinusD,
    MMinusD,

    DAndA,
    DAndM,

    DOrA,
    DOrM
};

} // namespace Hasm::Model
