# test sources:

set(source_files
    Assembler.test.cpp
    AssemblerEngineConfig.test.cpp
    Coder.test.cpp
    CommandLineParser.test.cpp
    FileHandler.test.cpp
    HackCommandParser.computation.test.cpp
    HackCommandParser.label.test.cpp
    HackCommandParser.load.test.cpp
    Parser.test.cpp
    SymbolTable.test.cpp)

# executable:

add_executable(test_suite ${source_files})
set_target_properties(test_suite PROPERTIES CXX_STANDARD 14)

target_link_libraries(test_suite
  PRIVATE
    hack_assembler
    Catch2::Catch2WithMain)

add_test(NAME HasmTestSuite COMMAND test_suite)
