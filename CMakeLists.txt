cmake_minimum_required(VERSION 2.8)
project(cgads)

set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -std=c++11 -Wall")

include_directories(${PROJECT_SOURCE_DIR}/include)

# aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LISTS)

set(SRC_LISTS 
    src/algorithm.cc 
    src/linear_list_single.cc 
    src/tree_binary.cc)

add_library(cgads SHARED ${SRC_LISTS})

add_executable(sparse_matrix src/sparse_matrix.cc)


################ google test ################
enable_testing()
find_package(GTest REQUIRED)
if(GTest_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS})
endif()
add_subdirectory(unit_test)
add_test(NAME ./unit_test/unit_test.run COMMAND ./unit_test/unit_test.run)
