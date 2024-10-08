add_executable(
  hasm_assembler_tests
  src/Assembler.test.cpp
  src/AssemblerEngineConfig.test.cpp
  src/Coder.test.cpp
  src/InstructionParser.computation.test.cpp
  src/InstructionParser.label.test.cpp
  src/InstructionParser.load.test.cpp
  src/Parser.test.cpp
  src/SymbolTable.test.cpp
)

target_compile_features(hasm_assembler_tests PUBLIC cxx_std_20)

set_target_properties(
  hasm_assembler_tests
  PROPERTIES
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    COMPILE_WARNING_AS_ERROR ON
)

target_link_libraries(
  hasm_assembler_tests
  PRIVATE
    hack_assembler
    Catch2::Catch2WithMain
)

add_test(NAME HasmTestSuite COMMAND hasm_assembler_tests)
