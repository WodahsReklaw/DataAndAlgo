cmake_minimum_required(VERSION 3.5.0)

add_executable(heap_exercises ${PROJECT_SOURCE_DIR}/heap.cpp)
add_executable(max_subarray ${PROJECT_SOURCE_DIR}/max_subarray.cpp)
target_link_libraries(heap_exercises project_lib)
target_link_libraries(max_subarray project_lib)
