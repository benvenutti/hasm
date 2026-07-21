# hack_assembler library:

add_library(
  hack
  INTERFACE
  include/Hack/InstructionType.hpp
  include/Hack/Hack.hpp
  include/Hack/Word.hpp
)

apply_target_options(hack)
apply_target_warnings(hack)
apply_target_coverage(hack)

target_include_directories(
  hack
  INTERFACE
    include
)
