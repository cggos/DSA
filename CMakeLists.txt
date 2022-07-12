cmake_minimum_required(VERSION 3.0)
project(DSA)

set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -std=c++11 -Wall")

include_directories(${PROJECT_SOURCE_DIR})

aux_source_directory(${PROJECT_SOURCE_DIR}/linked_list SRC_LL)
aux_source_directory(${PROJECT_SOURCE_DIR}/tree SRC_TREE)

add_executable(linked_list ${SRC_LL})
add_executable(binary_tree ${SRC_TREE})
add_executable(sparse_matrix mix/sparse_matrix.cc)

# alg
add_executable(algorithm alg/algorithm.cc)
add_executable(mem_align alg/mem_align.cpp)
add_executable(array_string alg/array_string.cpp)
add_executable(class00 alg/class00.cpp)
add_executable(permutation_combination alg/permutation_combination.cpp)
add_executable(smallest_bounding_rectangle alg/smallest_bounding_rectangle.cpp)
add_executable(testyh alg/testyh.cpp)

# ############### google test ################
enable_testing()
find_package(GTest)

if(GTest_FOUND)
    include_directories(${GTEST_INCLUDE_DIRS})
    add_subdirectory(unit_test)
    add_test(NAME ./unit_test/unit_test.run COMMAND ./unit_test/unit_test.run)
endif()
