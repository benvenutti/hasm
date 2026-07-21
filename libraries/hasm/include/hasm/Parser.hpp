#pragma once

#include <Hack/InstructionType.hpp>

#include <istream>
#include <optional>
#include <string>

namespace Hasm
{

class Parser
{
public:
    enum class Status
    {
        start_of_file,
        valid_instruction,
        invalid_instruction,
        end_of_file
    };

    explicit Parser( std::istream& in );

    bool advance();

    Status                                 getStatus() const;
    const std::string&                     getInstruction() const;
    std::optional< Hack::InstructionType > getInstructionType() const;
    size_t                                 getCurrentLineNumber() const;

    std::string symbol() const;
    std::string dest() const;
    std::string comp() const;
    std::string jump() const;

    bool reset();

private:
    bool readNextLine( std::string& str );

    void setInstruction( std::string instruction );

    std::istream&                          m_input;
    std::string                            m_instruction{};
    std::optional< Hack::InstructionType > m_instructionType{};
    size_t                                 m_lineNumber{ 0u };
    Status                                 m_status{ Status::start_of_file };
};

} // namespace Hasm
