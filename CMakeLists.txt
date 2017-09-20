cmake_minimum_required(VERSION 3.0)

# yage library cmakelists.txt
project(YetAnotherGameEngine)

# set standard
set(CMAKE_CXX_STANDARD 14)

# set the test sources
set(YAGE_TEST_DIR ${PROJECT_SOURCE_DIR}/tests)

# set binary directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# find libraries
find_package(OpenGL REQUIRED)

# adding libraries
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/yage)

include(cmake/cppcheck.cmake)

if($ENV{UNIT_TESTS})
  # enable tests
  enable_testing()
  set(SIMULATION_RUNS 100)

  function(make_test test_name cycles)
    add_executable(${test_name} ${YAGE_TEST_DIR}/${test_name}.cpp)
    target_link_libraries(${test_name}
      gtest_main
      yage)
    add_test(NAME ${test_name} COMMAND ${test_name} --gtest_repeat=${cycles} --gtest_break_on_failure)
  endfunction(make_test)

  make_test(yagetest ${SIMULATION_RUNS})
  make_test(matrixtest ${SIMULATION_RUNS})
  make_test(particlebodytest ${SIMULATION_RUNS})
  make_test(windowtest ${SIMULATION_RUNS})
endif()
