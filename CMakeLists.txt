cmake_minimum_required(VERSION 3.6 FATAL_ERROR)
project(hasm VERSION 0.2.1 LANGUAGES CXX)

# build settings:

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the build type" FORCE)
endif()

set(CMAKE_CXX_FLAGS_RELEASE -O2)

# 3rd-party dependencies:

find_package(Boost 1.78
  COMPONENTS
    filesystem
    program_options
    regex
    system
    REQUIRED)

include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1
)

FetchContent_MakeAvailable(Catch2)

# compiler definitions:

if(MSVC)
  add_compile_options(/W4 /w14545 /w34242 /w34254 /w34287 /w44263 /w44265 
    /w44296 /w44311 /w44826 /we4289 /w14546 /w14547 /w14549 /w14555 /w14619 
    /w14905 /w14906 /w14928)
else()
  add_compile_options(-Wall -Wextra -Wconversion -Wsign-conversion -Wshadow
    -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wcast-qual -Wunused
    -Woverloaded-virtual -pedantic)
endif()

# hack_assembler library:

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

configure_file(
  ${PROJECT_SOURCE_DIR}/include/HasmConfig.hpp.in
  ${PROJECT_BINARY_DIR}/include/HasmConfig.hpp)

add_library(hack_assembler 
  ${hack_assembler_source_files} 
  ${hack_assembler_header_files})

target_compile_features(hack_assembler PUBLIC cxx_std_17)

target_include_directories(hack_assembler
  PUBLIC
    include
    ${PROJECT_BINARY_DIR}/include)

target_link_libraries(hack_assembler
  PUBLIC
    Boost::boost
  PRIVATE
    Boost::filesystem
    Boost::program_options
    Boost::regex
    Boost::system)

# hasm executable:

add_executable(hasm src/main.cpp)

target_compile_features(hasm PUBLIC cxx_std_17)

target_link_libraries(hasm
  PRIVATE
    hack_assembler)

# unit tests:

enable_testing()
include(CTest)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
