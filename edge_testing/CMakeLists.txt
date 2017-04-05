cmake_minimum_required(VERSION 3.0)

find_package(GTest REQUIRED)
link_libraries(${GTEST_LIBRARIES})

add_executable(test_runner WIN32
    ../feature_code/Link_List.cpp
    edge_testings.cpp
    main.cpp)
