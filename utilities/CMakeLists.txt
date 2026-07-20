# utilities library:

add_library(
  utilities
  STATIC
  include/utilities/CommandLineParser.hpp
  src/utilities/CommandLineParser.cpp
)

apply_target_options(utilities)
apply_target_warnings(utilities)
apply_target_coverage(utilities)

target_include_directories(utilities PUBLIC include)

target_link_libraries(utilities PRIVATE CLI11::CLI11)

# tests:

if(BUILD_TESTS)
  add_subdirectory(tests)
endif()
