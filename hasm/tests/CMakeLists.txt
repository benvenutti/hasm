add_executable(
  hasm_assembler_tests
  src/Assembler.test.cpp
  src/AssemblerEngineConfig.test.cpp
  src/Coder.test.cpp
  src/CommandLineParser.test.cpp
  src/FileHandler.test.cpp
  src/HackCommandParser.computation.test.cpp
  src/HackCommandParser.label.test.cpp
  src/HackCommandParser.load.test.cpp
  src/Parser.test.cpp
  src/SymbolTable.test.cpp
)

target_compile_features(hasm_assembler_tests PUBLIC cxx_std_17)

target_link_libraries(
  hasm_assembler_tests
  PRIVATE
    hack_assembler
    Boost::boost
    Catch2::Catch2WithMain
)

add_test(NAME HasmTestSuite COMMAND hasm_assembler_tests)
