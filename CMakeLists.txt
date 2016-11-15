cmake_minimum_required(VERSION 2.8)
project(hasm)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX")
    set(dialect "")
else ()
    set(warnings "-Wall -Wextra -std=c++11")
    set(dialect "-std=c++11")
endif ()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${dialect} ${warnings}")

set(HASM_VERSION_MAJOR 0)
set(HASM_VERSION_MINOR 2)
set(HASM_VERSION_PATCH 0)

configure_file(
        "${PROJECT_SOURCE_DIR}/include/HasmConfig.hpp.in"
        "${PROJECT_BINARY_DIR}/include/HasmConfig.hpp")

include_directories("${PROJECT_BINARY_DIR}/include")

find_package(Boost COMPONENTS
        system
        filesystem
        program_options
        unit_test_framework
        regex
        REQUIRED)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)
