if (NOT Boost_USE_STATIC_LIBS)
    add_definitions(-DBOOST_TEST_DYN_LINK)
endif ()

file(GLOB test_sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

include_directories(${Boost_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include)

foreach (test_source ${test_sources})
    get_filename_component(test_name ${test_source} NAME_WE)
    add_executable(${test_name} ${test_source})

    target_link_libraries(${test_name}
            hasm
            ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

    set_target_properties(${test_name} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/testBin)

    add_test(NAME ${test_name}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/testBin
            COMMAND ${CMAKE_CURRENT_BINARY_DIR}/testBin/${test_name})
endforeach (test_source)
