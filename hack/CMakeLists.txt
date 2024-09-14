# hack_assembler library:

add_library(
  hack
  INTERFACE
  include/Hack/InstructionType.hpp
  include/Hack/Hack.hpp
  include/Hack/Word.hpp
)

target_compile_features(hack INTERFACE cxx_std_20)

set_target_properties(
  hack
  PROPERTIES
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    COMPILE_WARNING_AS_ERROR ON
)

target_include_directories(
  hack
  INTERFACE
    include
)
