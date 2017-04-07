add_executable(edge_test_runner WIN32
  edge_testings.cpp
  )
target_link_libraries(edge_test_runner
  gtest
  gtest_main
  linked_list_lib
  )
