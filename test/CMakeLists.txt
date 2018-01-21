add_executable(sort_test sort_test.cpp)
add_executable(heap_test heap_test.cpp)

target_link_libraries(sort_test project_lib gtest_main)
target_link_libraries(heap_test project_lib gtest_main)

add_test(NAME sort_test COMMAND sort_test)
add_test(NAME heap_test COMMAND heap_test)
