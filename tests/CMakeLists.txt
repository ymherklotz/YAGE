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

function(make_test test_name cycles)
  add_executable("${test_name}test" ${test_name}/test.cpp)
  target_link_libraries("${test_name}test"
    gtest_main
    yage)
  add_test(NAME ${test_name} COMMAND "${test_name}test" --gtest_repeat=${cycles} --gtest_break_on_failure)
endfunction(make_test)

make_test(yage 1)
make_test(matrix ${SIMULATION_RUNS})
make_test(particlebody 100)
make_test(window ${SIMULATION_RUNS})
make_test(spritesheet ${SIMULATION_RUNS})
make_test(vector3 ${SIMULATION_RUNS})
make_test(vector4 ${SIMULATION_RUNS})
make_test(log 1)
make_test(thread 1)
make_test(syncqueue 1)
make_test(active 1)
make_test(struct ${SIMULATION_RUNS})
make_test(engine ${SIMULATION_RUNS})
make_test(render ${SIMULATION_RUNS})
