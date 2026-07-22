# Test executable:

add_executable(hasm_tests)

apply_target_options(hasm_tests)
apply_target_warnings(hasm_tests)
apply_target_coverage(hasm_tests)

target_sources(hasm_tests
    PRIVATE
        src/Assembler.test.cpp
        src/AssemblerEngine.test.cpp
        src/AssemblerOptions.test.cpp
        src/Coder.test.cpp
        src/InstructionParser.computation.test.cpp
        src/InstructionParser.label.test.cpp
        src/InstructionParser.load.test.cpp
        src/Parser.test.cpp
        src/SymbolTable.test.cpp
)

target_compile_definitions(hasm_tests
    PRIVATE
        HASM_TEST_INPUT="${PROJECT_SOURCE_DIR}/tests/input"
)


# Dependencies:

target_link_libraries(hasm_tests
    PRIVATE
        hasm
        Catch2::Catch2WithMain
)


# Test registration:

add_test(
    NAME    HasmTestSuite
    COMMAND hasm_tests
)
