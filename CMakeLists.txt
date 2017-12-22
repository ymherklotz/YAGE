cmake_minimum_required(VERSION 3.0)

# yage library cmakelists.txt
project(yage
  VERSION 0.1.3.0
  LANGUAGES CXX)

# set standard
set(CMAKE_CXX_STANDARD 14)

# find other libraries from source
set(EXTERNAL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external)

# GLFW3
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(${EXTERNAL_DIR}/glfw)

# glad
add_subdirectory(${EXTERNAL_DIR}/glad)

# yage
file(GLOB YAGE_CORE_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} yage/core/*.cpp)
file(GLOB YAGE_MATH_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} yage/math/*.cpp)
file(GLOB YAGE_PHYSICS_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} yage/physics/*.cpp)
file(GLOB YAGE_UTIL_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} yage/util/*.cpp)
file(GLOB YAGE_CURRENT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} yage/*.cpp)

set(YAGE_SOURCES
  ${YAGE_CORE_SOURCES}
  ${YAGE_PHYSICS_SOURCES}
  ${YAGE_MATH_SOURCES}
  ${YAGE_UTIL_SOURCES}
  ${YAGE_CURRENT_SOURCES})

add_library(yage
  ${YAGE_SOURCES})

target_include_directories(yage
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/yage
  ${EXTERNAL_DIR}/glm
  ${EXTERNAL_DIR}/rapidjson/include)

target_link_libraries(yage
  glfw
  ${GLFW_LIBRARIES}
  glad)

if(YAGE_BUILD_TESTS)
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif(YAGE_BUILD_TESTS)
