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
        src/hasm/Assembler.cpp
        src/hasm/AssemblerEngine.cpp
        src/hasm/Coder.cpp
        src/hasm/ErrorMessage.cpp
        src/hasm/InstructionParser.cpp
        src/hasm/Parser.cpp
        src/hasm/SymbolTable.cpp
        src/hasm/SymbolTableWriter.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
            ${CMAKE_CURRENT_BINARY_DIR}/include
        FILES
            include/hasm/Assembler.hpp
            include/hasm/AssemblerEngine.hpp
            include/hasm/AssemblerEngineConfig.hpp
            include/hasm/Coder.hpp
            include/hasm/ErrorMessage.hpp
            include/hasm/HackGrammar.hpp
            include/hasm/HackLex.hpp
            include/hasm/InstructionParser.hpp
            include/hasm/Parser.hpp
            include/hasm/PredefinedSymbols.hpp
            include/hasm/SymbolTable.hpp
            include/hasm/SymbolTableWriter.hpp
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
