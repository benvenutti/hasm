# External dependencies:

find_package(Qt6 REQUIRED COMPONENTS Gui)

qt_standard_project_setup(REQUIRES 6.9)


# Executable:

qt_add_executable(hasm-gui)

apply_target_options(hasm-gui)
apply_target_warnings(hasm-gui)

target_sources(hasm-gui
    PRIVATE
        src/main.cpp
)


# Dependencies:

target_link_libraries(hasm-gui
    PRIVATE
        Qt6::Gui
)
