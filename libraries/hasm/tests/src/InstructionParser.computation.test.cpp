#include <hasm/InstructionParser.hpp>

#include <catch2/catch_test_macros.hpp>

#include <string>
#include <vector>

namespace
{

const std::vector< std::string > dest{ "M", "D", "MD", "A", "AM", "AD", "AMD" };

const std::vector< std::string > comp{ "0",   "1",   "-1",  "D",   "A",   "!D",  "!A",  "-D",  "-A", "D+1",
                                       "A+1", "D-1", "A-1", "D+A", "D-A", "A-D", "D&A", "D|A", "M",  "!M",
                                       "-M",  "M+1", "M-1", "D+M", "D-M", "M-D", "D&M", "D|M" };

const std::vector< std::string > jump{ "JGT", "JEQ", "JGE", "JLT", "JNE", "JLE", "JMP" };

std::vector< std::string > combine( const std::vector< std::string >& itens1,
                                    const std::vector< std::string >& itens2,
                                    const std::string&                separator )
{
    std::vector< std::string > result;
    result.reserve( itens1.size() * itens2.size() );

    for ( const auto& a : itens1 )
    {
        for ( const auto& b : itens2 )
        {
            result.push_back( a + separator + b );
        }
    }

    return result;
}

const auto allComps = []() {
    const auto destAndComp        = combine( dest, comp, "=" );
    const auto compAndJump        = combine( comp, jump, ";" );
    const auto destAndCompAndJump = combine( destAndComp, jump, ";" );

    auto comps = comp;
    comps.reserve( destAndComp.size() + compAndJump.size() + destAndCompAndJump.size() );
    comps.insert( comps.end(), destAndComp.begin(), destAndComp.end() );
    comps.insert( comps.end(), compAndJump.begin(), compAndJump.end() );
    comps.insert( comps.end(), destAndCompAndJump.begin(), destAndCompAndJump.end() );

    return comps;
}();

} // namespace

SCENARIO( "parse valid computations", "[InstructionParser]" )
{
    for ( const auto& computation : allComps )
    {
        REQUIRE( Hasm::InstructionParser::isComputation( computation ) );
    }
}

SCENARIO( "parse invalid computations", "[InstructionParser]" )
{
    // invalid computations
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "D+X" ) );

    // invalid destinations
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "X=D+A" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "1=D+A" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "=D+A" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "D=X" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "D=2" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "D=" ) );

    // invalid computation and valid jump
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "X;JMP" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "2;JGT" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( ";JGE" ) );

    // valid computation and invalid jump
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "D;JM" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "D;JG" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "D;" ) );

    // invalid destination, valid computation and jump
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "d=D+1;JMP" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "0=D+1;JMP" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "=D+1;JMP" ) );

    // valid destination, invalid computation and valid jump
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "D=d+1;JMP" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "D=D+;JMP" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "D=;JMP" ) );

    // valid destination and computation, invalid jump
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "D=A+1;jmp" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "D=D+1;JM" ) );
    REQUIRE_FALSE( Hasm::InstructionParser::isComputation( "D=M+1;" ) );
}
