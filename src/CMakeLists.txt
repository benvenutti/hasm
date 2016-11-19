include_directories(${Boost_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include)

file(GLOB source_files ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
set(sources ${source_files})
list(REMOVE_ITEM sources ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_library(hasm ${sources})

target_link_libraries(hasm
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_PROGRAM_OPTIONS_LIBRARY}
        ${Boost_REGEX_LIBRARY})

add_executable(hasm_executable ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_link_libraries(hasm_executable hasm)

set_target_properties(hasm_executable PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
        OUTPUT_NAME hasm)
