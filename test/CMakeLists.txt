file(GLOB test_sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

foreach (test_source ${test_sources})
    get_filename_component(test_name ${test_source} NAME_WE)
    add_executable(${test_name} $<TARGET_OBJECTS:hasm_objects> ${test_source})

    target_link_libraries(${test_name}
            ${Boost_FILESYSTEM_LIBRARY}
            ${Boost_SYSTEM_LIBRARY}
            ${Boost_PROGRAM_OPTIONS_LIBRARY}
            ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

    set_target_properties(${test_name} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/testBin)

    add_test(NAME ${test_name}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/testBin
            COMMAND ${CMAKE_CURRENT_BINARY_DIR}/testBin/${test_name})
endforeach (test_source)