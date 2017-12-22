# Initializing google test
# prevents overriding the parent project's compiler/linter settings on windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/googletest)

add_executable(simplegame simplegame.cpp)
target_link_libraries(simplegame yage)

# enable tests
enable_testing()
set(SIMULATION_RUNS 1000)

function(make_test test_name cycles)
  add_executable(${test_name} ${test_name}.cpp)
  target_link_libraries(${test_name}
    gtest_main
    yage)
  add_test(NAME ${test_name} COMMAND ${test_name} --gtest_repeat=${cycles} --gtest_break_on_failure)
endfunction(make_test)

make_test(yagetest 1)
make_test(matrixtest ${SIMULATION_RUNS})
make_test(particlebodytest 100)
make_test(windowtest ${SIMULATION_RUNS})
make_test(spritesheettest ${SIMULATION_RUNS})
make_test(vector3test ${SIMULATION_RUNS})
make_test(vector4test ${SIMULATION_RUNS})
make_test(logtest 1)
make_test(threadtest 1)
make_test(syncqueuetest 1)
make_test(activetest 1)
make_test(structtest ${SIMULATION_RUNS})
