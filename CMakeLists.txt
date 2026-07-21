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

include(cmake/DefaultTargetSettings.cmake)
include(CMakeDependentOption)


# project options:

option(BUILD_HASM_CLI "Build the hasm command-line application" ON)
option(BUILD_TESTS "Build tests" ON)
cmake_dependent_option(CODE_COVERAGE "Enable code coverage" OFF "BUILD_TESTS" OFF)


# 3rd party dependencies:

if(BUILD_TESTS)
    include(cmake/third_party/Catch2.cmake)
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
