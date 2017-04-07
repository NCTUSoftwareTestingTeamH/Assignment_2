add_executable(decisiontable_testing WIN32
  decisiontable_testing.cpp
  )
target_link_libraries(decisiontable_testing
  gtest
  linked_list_lib
  )
