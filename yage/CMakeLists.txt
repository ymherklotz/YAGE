cmake_policy(SET CMP0048 NEW)

project(yage
  VERSION 0.1.1.0
  LANGUAGES CXX)

include(base/CMakeLists.txt)
include(physics/CMakeLists.txt)
include(math/CMakeLists.txt)

set(YAGE_SOURCES
  yage.cpp
  ${YAGE_BASE_SOURCES}
  ${YAGE_PHYSICS_SOURCES}
  ${YAGE_MATH_SOURCES})

set(${PROJECT_NAME}_DIR
  ${PROJECT_SOURCE_DIR})

add_library(${PROJECT_NAME}
  ${YAGE_SOURCES})

target_include_directories(${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
  ${OPENGL_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME}
  ${OPENGL_gl_LIBRARY}
  glfw
  glad)
