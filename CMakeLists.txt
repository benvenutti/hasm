cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

# project:

project(
  hasm
  DESCRIPTION  "hasm is an assembler for the nand2tetris hack platform"
  HOMEPAGE_URL https://github.com/benvenutti/hasm
  VERSION      0.3.0
  LANGUAGES    CXX
)


# cmake modules and scripts:

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# custom modules:
include(DefaultTargetSettings)

# standard/built-in modules:
include(CMakeDependentOption)
include(FetchContent)


# project options:

option(BUILD_HASM_CLI "Build the hasm command-line application" ON)
option(BUILD_TESTS "Build tests" ON)
cmake_dependent_option(CODE_COVERAGE "Enable code coverage" OFF "BUILD_TESTS" OFF)

# 3rd party dependencies:

FetchContent_Declare(
  cli11_proj
  GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
  GIT_TAG        v2.6.2
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

# testing:

if(BUILD_TESTS)
  enable_testing()
endif()

# subdirectories:

add_subdirectory(libraries)
add_subdirectory(apps)
