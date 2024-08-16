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

target_compile_features(test_suite PUBLIC cxx_std_17)

target_link_libraries(
  test_suite
  PRIVATE
    hack_assembler
    Boost::boost
    Catch2::Catch2WithMain)

add_test(NAME HasmTestSuite COMMAND test_suite)
