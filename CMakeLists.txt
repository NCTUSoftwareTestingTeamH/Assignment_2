cmake_minimum_required(VERSION 2.8)

project("software_testing_homework_2")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_subdirectory("${CMAKE_SOURCE_DIR}/third_party/googletest")
include_directories(SYSTEM "${CMAKE_SOURCE_DIR}/third_party/googletest/googletest/include")

add_subdirectory("./feature_code")
add_subdirectory("./edge_testing")
add_subdirectory("./decisiontable_testing")
add_subdirectory("./equivalence_testing")
