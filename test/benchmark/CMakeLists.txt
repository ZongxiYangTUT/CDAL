if(TEST_BENCHMARK)
  file(GLOB_RECURSE benchmark CMAKE_CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/test/benchmark/*.cpp")
  foreach(benchmarkfile IN LISTS benchmark)
      get_filename_component(benchmarkname ${benchmarkfile} NAME_WE)
      add_executable(${benchmarkname} ${benchmarkfile})
      target_link_libraries(${benchmarkname} PRIVATE ${CMAKE_PROJECT_NAME})
      target_include_directories(${benchmarkname} PRIVATE "${CMAKE_SOURCE_DIR}/include")
      target_compile_options(${benchmarkname} PRIVATE "-Wall" "-O0")
  endforeach()
endif()
