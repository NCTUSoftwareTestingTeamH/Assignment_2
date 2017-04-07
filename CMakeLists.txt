cmake_minimum_required(VERSION 2.8)

add_subdirectory("${CMAKE_SOURCE_DIR}/third_party/googletest")
include_directories(SYSTEM "${CMAKE_SOURCE_DIR}/third_party/googletest/googletest/include")

add_subdirectory("./feature_code")
add_subdirectory("./edge_testing")
add_subdirectory("./decisiontable_testing")
add_subdirectory("./equivalence_testing")
