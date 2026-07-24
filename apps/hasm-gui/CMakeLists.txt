# External dependencies:

find_package(Qt6 REQUIRED
    COMPONENTS
        Quick
        QuickControls2
)

qt_standard_project_setup(REQUIRES 6.9)


# Executable:

qt_add_executable(hasm-gui)

apply_target_options(hasm-gui)
apply_target_warnings(hasm-gui)

target_sources(hasm-gui
    PRIVATE
        src/main.cpp
)

qt_add_qml_module(hasm-gui
    URI     Hasm
    VERSION 1.0
    QML_FILES
        src/qml/Main.qml
)


# Dependencies:

target_link_libraries(hasm-gui
    PRIVATE
        Qt6::Quick
        Qt6::QuickControls2
)
