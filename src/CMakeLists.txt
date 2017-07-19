include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB source_files ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
set(sources ${source_files})
list(REMOVE_ITEM sources ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_library(hasm ${sources})

target_link_libraries(hasm
    Boost::filesystem
    Boost::program_options
    Boost::regex
    Boost::system)

add_executable(hasm_executable ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_link_libraries(hasm_executable hasm)

set_target_properties(hasm_executable PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
        OUTPUT_NAME hasm)
