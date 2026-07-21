# External dependencies:

include(cmake/third_party/CLI11.cmake)


# Executable:

add_executable(hasm-cli)

apply_target_options(hasm-cli)
apply_target_warnings(hasm-cli)

target_sources(hasm-cli
    PRIVATE
        src/CommandLineParser.cpp
        src/CommandLineParser.hpp
        src/main.cpp
)


# Dependencies:

target_link_libraries(hasm-cli
    PRIVATE
        hasm
        CLI11::CLI11
)
