# hack_assembler library:

add_library(
  hack_assembler
  STATIC
  include/hasm/Assembler.hpp
  include/hasm/AssemblerEngine.hpp
  include/hasm/AssemblerEngineConfig.hpp
  include/hasm/Coder.hpp
  include/hasm/ErrorMessage.hpp
  include/hasm/Hack.hpp
  include/hasm/HackCommandParser.hpp
  include/hasm/HackGrammar.hpp
  include/hasm/HackLex.hpp
  include/hasm/Hasm.hpp
  include/hasm/Parser.hpp
  include/hasm/SymbolTable.hpp
  include/hasm/SymbolTableWriter.hpp
  src/hasm/Assembler.cpp
  src/hasm/AssemblerEngine.cpp
  src/hasm/Coder.cpp
  src/hasm/ErrorMessage.cpp
  src/hasm/HackCommandParser.cpp
  src/hasm/Parser.cpp
  src/hasm/SymbolTable.cpp
  src/hasm/SymbolTableWriter.cpp
)

target_compile_features(hack_assembler PUBLIC cxx_std_20)

set_target_properties(
  hack_assembler
  PROPERTIES
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

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

# tests:

if(BUILD_TESTS)
  add_subdirectory(tests)
endif()
