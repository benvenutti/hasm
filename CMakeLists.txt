cmake_minimum_required(VERSION 2.8)
project(hasm)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX")
    set(dialect "")
else
    set(warnings "-Wall -Wextra -std=c++11")
    set(dialect "-std=c++11")
endif ()

find_package(Boost COMPONENTS system filesystem program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${dialect} ${warnings}")

set(sourcefiles
        src/Assembler.cpp
        src/AssemblerEngine.cpp
        src/Coder.cpp
        src/FileHandler.cpp
        src/Parser.cpp
        src/SymbolTable.cpp
        src/main.cpp)

include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable(hasm ${sourcefiles})

target_link_libraries(hasm
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_PROGRAM_OPTIONS_LIBRARY})