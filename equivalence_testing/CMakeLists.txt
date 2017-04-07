link_libraries(gtest gtest_main linked_list_lib)

add_executable(StrongFormTesting WIN32
  "./StrongFormTesting.cpp"
  )

add_executable(WeakFormTesting WIN32
  "./WeakFormTesting.cpp"
  )
