cmake_minimum_required(VERSION 3.21)
project(CDAL)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

file(GLOB_RECURSE sources CMAKE_CONFIGURE_DEPENDS src/*.c)

add_library(${CMAKE_PROJECT_NAME} SHARED ${sources})
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE include)

option(TEST_TEST "open test" ON)
option(TEST_BENCHMARK "open benchmark" ON)

add_subdirectory(test/test)
add_subdirectory(test/benchmark)
