cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

# project:

project(
  hasm
  DESCRIPTION  "hasm is an assembler for the nand2tetris hack platform"
  HOMEPAGE_URL https://github.com/benvenutti/hasm
  VERSION      0.2.1
  LANGUAGES    CXX
)

# modules:

include(CMakeDependentOption)
include(FetchContent)

# project options:

option(BUILD_APP_COMMAND_LINE "Build hasm command line application" ON)
option(BUILD_TESTS "Build tests" ON)
cmake_dependent_option(CODE_COVERAGE "Enable code coverage" OFF "BUILD_TESTS" OFF)

# 3rd party dependencies:

FetchContent_Declare(
  cli11_proj
  GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
  GIT_TAG        v2.3.2
)

FetchContent_MakeAvailable(cli11_proj)

if(BUILD_TESTS)
  FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.7.0
  )

  FetchContent_MakeAvailable(Catch2)
endif()

# build type:

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the build type" FORCE)
endif()

# compiler options:

if(MSVC)
  add_compile_options(
    # warnings:
    /W4 /w14545 /w34242 /w34254 /w34287 /w44263 /w44265  /w44296 /w44311 /w44826
    /we4289 /w14546 /w14547 /w14549 /w14555 /w14619 /w14905 /w14906 /w14928

    # optimization levels:
    $<$<CONFIG:RELEASE>:/O2>
    $<$<CONFIG:DEBUG>:/Od>
  )
else()
  add_compile_options(
    # warnings:
    -Wall -Wconversion -Wsign-conversion -Wshadow -Wnon-virtual-dtor -Wcast-qual
    -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -pedantic -Wextra

    # optimization levels:
    $<$<CONFIG:RELEASE>:-O3>
    $<$<CONFIG:DEBUG>:-O0>

    # coverage:
    $<$<BOOL:${CODE_COVERAGE}>:-coverage>
  )

  add_link_options(
    # coverage:
    $<$<BOOL:${CODE_COVERAGE}>:-coverage>
  )
endif()

# testing:

if(BUILD_TESTS)
  enable_testing()
endif()

# subdirectories:

add_subdirectory(hack)
add_subdirectory(hasm)
add_subdirectory(utilities)

if(BUILD_APP_COMMAND_LINE)
  add_subdirectory(app-command-line)
endif()
