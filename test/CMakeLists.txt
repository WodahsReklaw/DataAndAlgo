add_executable(sort_test sort_test.cpp)

target_link_libraries(sort_test project_lib gtest_main)

add_test(NAME sort_test COMMAND sort_test)
