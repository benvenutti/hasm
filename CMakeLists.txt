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

find_package(Boost COMPONENTS
        system
        filesystem
        program_options
        unit_test_framework
        regex
        REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

include_directories("${CMAKE_SOURCE_DIR}/include")

file(GLOB source_files "${CMAKE_SOURCE_DIR}/src/*.cpp")
set(sources ${source_files})
list(REMOVE_ITEM sources ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_library(hasm_objects OBJECT ${sources})
add_executable(hasm $<TARGET_OBJECTS:hasm_objects>
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_link_libraries(hasm
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_PROGRAM_OPTIONS_LIBRARY})

enable_testing()
add_subdirectory(test)
