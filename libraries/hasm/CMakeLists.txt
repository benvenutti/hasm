# hack_assembler library:

add_library(
  hack_assembler
  STATIC
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
  src/hasm/Assembler.cpp
  src/hasm/AssemblerEngine.cpp
  src/hasm/Coder.cpp
  src/hasm/ErrorMessage.cpp
  src/hasm/InstructionParser.cpp
  src/hasm/Parser.cpp
  src/hasm/SymbolTable.cpp
  src/hasm/SymbolTableWriter.cpp
)

apply_target_options(hack_assembler)
apply_target_warnings(hack_assembler)
apply_target_coverage(hack_assembler)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/include/hasm/HasmInfo.hpp.in
  ${PROJECT_BINARY_DIR}/include/hasm/HasmInfo.hpp
)

target_include_directories(
  hack_assembler
  PUBLIC
    include
    ${PROJECT_BINARY_DIR}/include
)

target_link_libraries(
  hack_assembler
  PUBLIC
    hack
)

# tests:

if(BUILD_TESTS)
  add_subdirectory(tests)
endif()
