# hasm executable:

add_executable(hasm src/main.cpp)

apply_target_options(hasm)
apply_target_warnings(hasm)

target_link_libraries(
  hasm
  PRIVATE
    hack_assembler
    utilities
)
