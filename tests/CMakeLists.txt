if (NOT Boost_USE_STATIC_LIBS)
  add_definitions(-DBOOST_TEST_DYN_LINK)
endif()

set(test_sources_files
  AssemblerEngineConfig_test.cpp
  Assembler_test.cpp
  BoostTest_config.cpp
  Coder_test.cpp
  CommandLineParser_test.cpp
  FileHandler_test.cpp
  HackCommandParser_test.cpp
  HackGrammar_computation_test.cpp
  HackGrammar_destination_test.cpp
  HackGrammar_jump_test.cpp
  HackGrammar_label_test.cpp
  HackGrammar_load_test.cpp
  HackLex_test.cpp
  Parser_test.cpp
  SymbolTable_test.cpp)

add_executable(test_suite ${test_sources_files})
set_target_properties(test_suite PROPERTIES CXX_STANDARD 14)

target_link_libraries(test_suite
  PRIVATE
    hack_assembler
    Boost::unit_test_framework)

add_test(NAME HasmTestSuite COMMAND test_suite)

# catch2 tests:

set(catch_source_files
    Assembler.test.cpp
    AssemblerEngineConfig.test.cpp
    catch.setup.cpp
    Coder.test.cpp
    CommandLineParser.test.cpp
    FileHandler.test.cpp
    HackCommandParser.test.cpp
    Parser.test.cpp
    SymbolTable.test.cpp)

add_executable(catch_test_suite ${catch_source_files})
set_target_properties(catch_test_suite PROPERTIES CXX_STANDARD 14)

target_link_libraries(catch_test_suite
  PRIVATE
    hack_assembler
    catch2)

add_test(NAME HasmTestSuiteCatch COMMAND catch_test_suite)
