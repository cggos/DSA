# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable( unit_test.run gtest_main.cc
    t_linear_list.cc)

target_link_libraries(unit_test.run cgads gtest pthread)
