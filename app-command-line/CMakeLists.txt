# hasm executable:

add_executable(hasm src/main.cpp)

target_compile_features(hasm PUBLIC cxx_std_17)

target_link_libraries(hasm PRIVATE hack_assembler)
