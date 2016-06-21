cmake_minimum_required(VERSION 3.2)
project(hasm)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warnings} -std=c++11")

set(SOURCE_FILES
    src/Assembler.cpp
    src/AssemblerEngine.cpp
    src/Coder.cpp
    src/FileHandler.cpp
    src/Parser.cpp
    src/SymbolTable.cpp
    src/main.cpp)

include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable(hasm ${SOURCE_FILES})