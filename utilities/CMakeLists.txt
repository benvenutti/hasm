# utilities library:

add_library(
  utilities
  STATIC
  include/utilities/CommandLineParser.hpp
  src/utilities/CommandLineParser.cpp
)

target_compile_features(utilities PUBLIC cxx_std_20)

set_target_properties(
  utilities
  PROPERTIES
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    COMPILE_WARNING_AS_ERROR ON
)

target_include_directories(utilities PUBLIC include)

target_link_libraries(utilities PRIVATE CLI11::CLI11)

# tests:

if(BUILD_TESTS)
  add_subdirectory(tests)
endif()
