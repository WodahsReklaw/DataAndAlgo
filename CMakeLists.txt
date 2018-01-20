cmake_minimum_required(VERSION 3.5.0)

project(DataAndAlgo CXX)

SET(CMAKE_C_COMPILER /usr/bin/clang)
SET(CMAKE_CXX_COMPILER /usr/bin/clang++)
# Use C++17 since its good to prepare for the __future__.
set(CMAKE_CXX_STANDARD 14)
# Include symbols in executables, include all warning info.
set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17")

# Setup googletest!
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in external/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/external)
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/external)
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
  ${CMAKE_BINARY_DIR}/googletest-build
  EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed.
# SET(CMAKE_INCLUDE_CURRENT_DIR ON)



# Include our source and header files into a library
# called project_lib.
set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
include_directories(include)
include_directories(src)
file(GLOB PROJECT_SRCS
  ${PROJECT_SOURCE_DIR}/"*.tpp"
  ${PROJECT_SOURCE_DIR}/"*.cpp")

add_library(project_lib ${PROJECT_SRCS})
set_target_properties(project_lib PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(bin)
add_subdirectory(test)
