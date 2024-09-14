add_executable(
  utilities_tests
  src/CommandLineParser.test.cpp
)

target_compile_features(utilities_tests PUBLIC cxx_std_20)

set_target_properties(
  utilities_tests
  PROPERTIES
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    COMPILE_WARNING_AS_ERROR ON
)

target_link_libraries(
  utilities_tests
  PRIVATE
    utilities
    Catch2::Catch2WithMain
)

add_test(NAME UtilitiesTestSuite COMMAND utilities_tests)
