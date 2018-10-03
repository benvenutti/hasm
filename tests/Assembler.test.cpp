#include "Assembler.hpp"

#include <catch2/catch.hpp>

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace detail
{

struct Source
{
    std::string file;
    std::string reference;
};

const std::vector<Source> sources{ { "Add.asm", "Add.hack" },   //
                                   { "Max.asm", "Max.hack" },   //
                                   { "Pong.asm", "Pong.hack" }, //
                                   { "Rect.asm", "Rect.hack" } };

} // namespace detail

SCENARIO( "Add", "[Assembler]" )
{
    for ( const auto& src : detail::sources )
    {
        std::ifstream in{ src.file };
        std::ifstream inReference{ src.reference };

        REQUIRE( in.good() );
        REQUIRE( inReference.good() );

        std::stringstream out;
        Hasm::Assembler   assembler{ in, out };

        REQUIRE( assembler.assemble() == true );

        std::stringstream outReference;
        outReference << inReference.rdbuf();

        REQUIRE( out.str() == outReference.str() );
    }
}
