add_executable(
  utilities_tests
  src/CommandLineParser.test.cpp
)

apply_target_options(utilities_tests)
apply_target_warnings(utilities_tests)
apply_target_coverage(utilities_tests)

target_link_libraries(
  utilities_tests
  PRIVATE
    utilities
    Catch2::Catch2WithMain
)

add_test(NAME UtilitiesTestSuite COMMAND utilities_tests)
