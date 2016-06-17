cmake_minimum_required(VERSION 3.5)
project(hasm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

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