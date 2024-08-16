# test sources:

set(source_files
    src/Assembler.test.cpp
    src/AssemblerEngineConfig.test.cpp
    src/Coder.test.cpp
    src/CommandLineParser.test.cpp
    src/FileHandler.test.cpp
    src/HackCommandParser.computation.test.cpp
    src/HackCommandParser.label.test.cpp
    src/HackCommandParser.load.test.cpp
    src/Parser.test.cpp
    src/SymbolTable.test.cpp)

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
