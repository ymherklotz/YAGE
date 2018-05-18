# Initializing google test
# prevents overriding the parent project's compiler/linter settings on windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/googletest)

# enable tests
enable_testing()
set(SIMULATION_RUNS 1000)

function(make_test test_file_name cycles)
  string(REPLACE "_test.cpp" "" test_name ${test_file_name})
  add_executable("${test_name}test" ${test_file_name})
  target_link_libraries("${test_name}test"
    gtest_main
    yage)
  add_test(NAME ${test_name} COMMAND "${test_name}test" --gtest_repeat=${cycles} --gtest_break_on_failure)
endfunction(make_test)

file(GLOB YAGE_TEST_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *_test.cpp)

foreach(yage_test ${YAGE_TEST_SOURCES})
  make_test(${yage_test} 100)
endforeach()
