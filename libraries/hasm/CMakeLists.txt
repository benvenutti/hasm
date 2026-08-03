# Configuration:

configure_file(
    include/hasm/HasmInfo.hpp.in
    ${CMAKE_CURRENT_BINARY_DIR}/include/hasm/HasmInfo.hpp
)


# Library:

add_library(hasm STATIC)

apply_target_options(hasm)
apply_target_warnings(hasm)
apply_target_coverage(hasm)

target_sources(hasm
    PRIVATE
        src/hasm/parser/InstructionMatcher.cpp
        src/hasm/parser/InstructionParser.cpp
        src/hasm/parser/Parser.cpp
        src/hasm/Assembler.cpp
        src/hasm/AssemblerEngine.cpp
        src/hasm/Coder.cpp
        src/hasm/InstructionParser.cpp
        src/hasm/SymbolListingWriter.cpp
        src/hasm/SymbolTable.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
            ${CMAKE_CURRENT_BINARY_DIR}/include
        FILES
            include/hasm/language/Grammar.hpp
            include/hasm/language/Lex.hpp
            include/hasm/model/Comp.hpp
            include/hasm/model/Dest.hpp
            include/hasm/model/Instruction.hpp
            include/hasm/model/Jump.hpp
            include/hasm/model/Located.hpp
            include/hasm/model/ParseError.hpp
            include/hasm/model/SourceLocation.hpp
            include/hasm/parser/InstructionMatcher.hpp
            include/hasm/parser/InstructionParser.hpp
            include/hasm/parser/Parser.hpp
            include/hasm/Assembler.hpp
            include/hasm/AssemblerEngine.hpp
            include/hasm/AssemblerOptions.hpp
            include/hasm/Coder.hpp
            include/hasm/HackGrammar.hpp
            include/hasm/HackLex.hpp
            include/hasm/InstructionParser.hpp
            include/hasm/PredefinedSymbols.hpp
            include/hasm/SymbolListingWriter.hpp
            include/hasm/SymbolTable.hpp
            ${CMAKE_CURRENT_BINARY_DIR}/include/hasm/HasmInfo.hpp
)


# Dependencies:

target_include_directories(hasm
    PUBLIC
        include
        ${CMAKE_CURRENT_BINARY_DIR}/include
)

target_link_libraries(hasm
    PUBLIC
        hack
)


# Tests:

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
