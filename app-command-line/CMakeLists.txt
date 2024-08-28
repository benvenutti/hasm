# hasm executable:

add_executable(hasm src/main.cpp)

target_compile_features(hasm PUBLIC cxx_std_20)

set_target_properties(
  hasm
  PROPERTIES
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

target_link_libraries(
  hasm
  PRIVATE
    hack_assembler
    utilities
)
