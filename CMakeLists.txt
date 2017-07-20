cmake_minimum_required(VERSION 3.6 FATAL_ERROR)
project(hasm LANGUAGES CXX)

find_package(Boost COMPONENTS 
    filesystem
    program_options
    regex
    system
    unit_test_framework REQUIRED)

if(MSVC)
  add_definitions(/W4 /w14545 /w34242 /w34254 /w34287 /w44263 /w44265 /w44296
    /w44311 /w44826 /we4289 /w14546 /w14547 /w14549 /w14555 /w14619 /w14905
    /w14906 /w14928)
else()
  add_definitions(-Wall -Wextra -Wconversion -Wsign-conversion -Wshadow
    -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wcast-qual -Wunused
    -Woverloaded-virtual -pedantic)
endif()

set(HASM_VERSION_MAJOR 0)
set(HASM_VERSION_MINOR 2)
set(HASM_VERSION_PATCH 0)

configure_file(
    ${PROJECT_SOURCE_DIR}/include/HasmConfig.hpp.in
    ${PROJECT_BINARY_DIR}/include/HasmConfig.hpp)

include_directories(${PROJECT_BINARY_DIR}/include)
include_directories(include)

# hack_assembler library

set(hack_assembler_source_files
    src/Assembler.cpp
    src/AssemblerEngine.cpp
    src/Coder.cpp
    src/CommandLineParser.cpp
    src/ErrorMessage.cpp
    src/FileHandler.cpp
    src/HackCommandParser.cpp
    src/Parser.cpp
    src/SymbolTable.cpp
    src/SymbolTableWriter.cpp)

set(hack_assembler_header_files
    include/Assembler.hpp
    include/AssemblerEngine.hpp
    include/AssemblerEngineConfig.hpp
    include/Coder.hpp
    include/CommandLineParser.hpp
    include/ErrorMessage.hpp
    include/FileHandler.hpp
    include/Hack.hpp
    include/HackCommandParser.hpp
    include/HackGrammar.hpp
    include/HackLex.hpp
    include/Hasm.hpp
    include/Parser.hpp
    include/SymbolTable.hpp
    include/SymbolTableWriter.hpp)

add_library(hack_assembler 
    ${hack_assembler_source_files} 
    ${hack_assembler_header_files})

set_target_properties(hack_assembler PROPERTIES CXX_STANDARD 11)

target_link_libraries(hack_assembler
    Boost::filesystem
    Boost::program_options
    Boost::regex
    Boost::system)

# hasm executable

add_executable(hasm src/main.cpp)
set_target_properties(hasm PROPERTIES CXX_STANDARD 11)
target_link_libraries(hasm hack_assembler)

# unit tests

enable_testing(true)
add_subdirectory(test)
