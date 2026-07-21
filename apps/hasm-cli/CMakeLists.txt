add_executable(hasm-cli)

apply_target_options(hasm-cli)
apply_target_warnings(hasm-cli)

target_sources(hasm-cli
    PRIVATE
        src/main.cpp
)

target_link_libraries(hasm-cli
    PRIVATE
        hack_assembler
        utilities
)
