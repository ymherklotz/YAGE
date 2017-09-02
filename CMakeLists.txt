# ----------------------------------------------------------------------------
# CMakeLists.txt
#
# Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
# See file LICENSE for more details
# ----------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.0)

# yage library cmakelists.txt
project(yage)

# set version numbers
set(YAGE_MAJOR_VERSION 0)
set(YAGE_MINOR_VERSION 1)
set(YAGE_PATCH_VERSION 1)
set(YAGE_VERSION
  "v${YAGE_MAJOR_VERSION}.${YAGE_MINOR_VERSION}.${YAGE_PATCH_VERSION}")

# set standard
set(CMAKE_CXX_STANDARD 14)

# set the test sources
set(YAGE_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(YAGE_TEST_DIR ${PROJECT_SOURCE_DIR}/test)
set(YAGE_LIBRARIES yage)

# add include directory
set(YAGE_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include/YAGE)

# set binary directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# add sources to library
set(YAGE_SOURCES
  ${PROJECT_SOURCE_DIR}/src/body.cpp
  ${PROJECT_SOURCE_DIR}/src/camera2d.cpp
  ${PROJECT_SOURCE_DIR}/src/glslprogram.cpp
  ${PROJECT_SOURCE_DIR}/src/imageloader.cpp
  ${PROJECT_SOURCE_DIR}/src/inputmanager.cpp
  ${PROJECT_SOURCE_DIR}/src/iomanager.cpp
  ${PROJECT_SOURCE_DIR}/src/particlebody.cpp
  ${PROJECT_SOURCE_DIR}/src/picopng.cpp
  ${PROJECT_SOURCE_DIR}/src/rectanglecollider.cpp
  ${PROJECT_SOURCE_DIR}/src/resourcemanager.cpp
  ${PROJECT_SOURCE_DIR}/src/rigidbody.cpp
  ${PROJECT_SOURCE_DIR}/src/spritebatch.cpp
  ${PROJECT_SOURCE_DIR}/src/sprite.cpp
  ${PROJECT_SOURCE_DIR}/src/texturecache.cpp
  ${PROJECT_SOURCE_DIR}/src/window.cpp)

# Initializing google test
# prevents overriding the parent project's compiler/linter settings on windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${PROJECT_SOURCE_DIR}/googletest)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# find libraries
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)

# set include directory
include_directories(${YAGE_INCLUDE_DIR})

# make it a static library
add_library(${PROJECT_NAME} ${YAGE_SOURCES})

set(YAGE_LIB_DEP_L "yage;${OPENGL_LIBRARIES};${GLEW_LIBRARIES};${SDL2_LIBRARIES}")

message("${YAGE_LIB_DEP_L}")

# enable tests
enable_testing()
set(SIMULATION_RUNS 1000)

function(make_test test_name cycles)
  add_executable(${test_name} ${YAGE_TEST_DIR}/${test_name}.cpp)
  target_link_libraries(${test_name} gtest_main ${YAGE_LIB_DEP_L})
  add_test(NAME ${test_name} COMMAND ${test_name} --gtest_repeat=${cycles} --gtest_break_on_failure)
endfunction(make_test)

make_test(yagetest 10)
make_test(matrixtest ${SIMULATION_RUNS})
make_test(particlebodytest ${SIMULATION_RUNS})
make_test(windowtest ${SIMULATION_RUNS})
