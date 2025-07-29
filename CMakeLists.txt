cmake_minimum_required(VERSION 3.21)
project(CDAL)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

file(GLOB_RECURSE sources CMAKE_CONFIGURE_DEPENDS src/*.c)
file(GLOB_RECURSE test CMAKE_CONFIGURE_DEPENDS test/*.c)

add_library(${PROJECT_NAME} SHARED ${sources})
target_include_directories(${PROJECT_NAME} PRIVATE include)

foreach(mainfile IN LISTS test)
    get_filename_component(mainname ${mainfile} NAME_WE)
    add_executable(${mainname} ${mainfile} ${sources})
    target_link_libraries(${mainname} PRIVATE ${PROJECT_NAME})
    target_include_directories(${mainname} PRIVATE include)
    target_compile_options(${mainname} PRIVATE "-Wall" "-O0")
endforeach()
