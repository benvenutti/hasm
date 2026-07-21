# Library:

add_library(hack INTERFACE)

# TODO: Revisit whether these helpers are appropriate for INTERFACE libraries.
apply_target_options(hack)
apply_target_warnings(hack)
apply_target_coverage(hack)

target_sources(hack
    INTERFACE
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/Hack/Hack.hpp
            include/Hack/InstructionType.hpp
            include/Hack/Word.hpp
)


# Dependencies:

target_include_directories(hack
    INTERFACE
        include
)
