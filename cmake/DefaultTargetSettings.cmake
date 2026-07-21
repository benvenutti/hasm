# Prevent double inclusion:

include_guard(GLOBAL)


# Target: default_target_options
#
# Default compiler and linker settings shared by every target in the project.
#
# Includes:
#   - Required C++ standard
#   - Compiler conformance settings
#
add_library(default_target_options INTERFACE)

target_compile_features(default_target_options INTERFACE cxx_std_20)

set_target_properties(default_target_options
    PROPERTIES
        INTERFACE_CXX_STANDARD_REQUIRED ON
        INTERFACE_CXX_EXTENSIONS        OFF
)

target_compile_options(default_target_options INTERFACE
    # MSVC
    $<$<CXX_COMPILER_ID:MSVC>:
    /permissive-     # Enforce strict standard C++ conformity (Disables legacy MSVC workarounds)
    /Zc:__cplusplus  # Force MSVC (__cplusplus macro) to report  the chosen C++20 standard value.
                     # See (https://learn.microsoft.com/en-us/cpp/build/reference/zc-cplusplus)
    /Zc:inline       # Removes unreferenced inline functions from object files. This can Speed up compilation
                     # and reduce binary size.
    >
)


# Target: default_target_warnings
#
# Default warning policy shared by every target in the project.
#
# Includes:
#   - Warning level
#   - Warnings as errors
#   - Extra diagnostics
#
add_library(default_target_warnings INTERFACE)

target_compile_options(default_target_warnings INTERFACE
    # MSVC (Windows) flags:
    $<$<CXX_COMPILER_ID:MSVC>:
    /W4     # Warning level 4 (Production standard, very strict)
    /WX     # Treat warnings as errors
    /w14545 # Function behavior change
    /w34242 # Possible data loss
    /w34254 # Narrowing conversion
    /w34287 # Unsigned/negative mismatch
    /w44263 # No virtual destructor
    /w44265 # Class has virtual functions but destructor isn't virtual
    /w44296 # Expression is always true/false
    /w44311 # Pointer truncation
    /w44826 # Conversion is sign-extended
    /we4289 # Treat loop-control misuse as error
    >

    # GCC / Clang flags:
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:
    -Wall                # Enable common warnings
    -Werror              # Treat warnings as errors
    -Wpedantic           # Enforce strict ISO C++
    -Wshadow             # Detect variable shadowing
    -Wunused             # Detect unused variables/functions
    -Wconversion         # Warn about implicit narrowing conversions
    -Wsign-conversion    # Warn about signed/unsigned conversions
    -Wnon-virtual-dtor   # Warn about polymorphic classes without virtual destructor
    -Wcast-qual          # Warn when const qualifiers are discarded
    -Wold-style-cast     # Warn about C-style casts
    -Wcast-align         # Warn about alignment-changing casts
    -Woverloaded-virtual # Warn about hidden virtual functions
    >
)


# Target: default_target_coverage
#
# Code coverage instrumentation.
#
# Enabled only when CODE_COVERAGE is ON.
#
add_library(default_target_coverage INTERFACE)

target_compile_options(default_target_coverage INTERFACE
    $<$<BOOL:${CODE_COVERAGE}>:
    -coverage # Enable gcov/llvm-cov instrumentation
    >
)

target_link_options(default_target_coverage INTERFACE
    $<$<BOOL:${CODE_COVERAGE}>:
    -coverage # Link coverage runtime
    >
)


# Function: apply_target_options
#
# Applies the project's default compiler and build configuration to a target.
# This function configures the target with the project's standard build settings,
# including:
#
#   - Required C++ language standard
#   - Compiler conformance options
#   - Link-Time Optimization (when supported)
#
# Call this once for every target built by the project.
#
function(apply_target_options target)
    if(NOT TARGET "${target}")
        message(FATAL_ERROR "apply_target_options(): '${target}' is not a CMake target.")
    endif()

    get_target_property(type ${target} TYPE)

    if(type STREQUAL "INTERFACE_LIBRARY")
        set(scope INTERFACE)
    else()
        set(scope PRIVATE)
    endif()

    target_link_libraries(${target} ${scope} default_target_options)
endfunction()


# Function: apply_target_warnings
#
# Applies the project's default compiler warning policy to a target.
# This function enables the project's standard warning level and treats warnings
# as errors. The exact warning flags are selected automatically based on the
# active compiler.
#
# Call this once for every target built by the project.
#
function(apply_target_warnings target)
    if(NOT TARGET "${target}")
        message(FATAL_ERROR "apply_target_warnings(): '${target}' is not a CMake target.")
    endif()

    get_target_property(type ${target} TYPE)

    if(type STREQUAL "INTERFACE_LIBRARY")
        set(scope INTERFACE)
    else()
        set(scope PRIVATE)
    endif()

    target_link_libraries(${target} ${scope} default_target_warnings)
endfunction()


# Function: apply_target_coverage
#
# Applies code coverage instrumentation to a target.
# This function configures compiler and linker flags required to generate coverage
# metrics (e.g., GCC/Clang gcov flags or MSVC coverage flags) for debug builds.
#
# Call this for executable or test targets where coverage tracking is required.
#
# Note: Ensure the build type supports instrumentation (typically Debug or RelWithDebInfo).
#
function(apply_target_coverage target)
    if(NOT TARGET "${target}")
        message(FATAL_ERROR "apply_target_coverage(): '${target}' is not a CMake target.")
    endif()

    get_target_property(type ${target} TYPE)

    if(type STREQUAL "INTERFACE_LIBRARY")
        set(scope INTERFACE)
    else()
        set(scope PRIVATE)
    endif()

    target_link_libraries(${target} ${scope} default_target_coverage)
endfunction()
