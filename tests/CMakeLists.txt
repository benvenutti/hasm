# test sources:

set( source_files
    Assembler.test.cpp
    catch.setup.cpp
    Coder.test.cpp
    CommandLineParser.test.cpp
    FileHandler.test.cpp
    HackCommandParser.computation.test.cpp
    HackCommandParser.label.test.cpp
    HackCommandParser.load.test.cpp
    Parser.test.cpp
    SymbolTable.test.cpp )

# executable:

add_executable( test_suite ${source_files} )

target_link_libraries( test_suite
  PRIVATE
    hack_assembler
    catch2 )

add_test( NAME HasmTestSuite COMMAND test_suite )
