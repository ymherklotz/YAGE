cmake_minimum_required(VERSION 3.0)

# yage library cmakelists.txt
project(yage
  VERSION 0.1.3.0
  LANGUAGES CXX)

option(YAGE_BUILD_TESTS "Build tests and ctest testing suite" ON)
option(YAGE_BUILD_DOCS "Build documentation using Doxygen" ON)

# set standard
set(CMAKE_CXX_STANDARD 14)

# adding more warnings to cmake
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall")

# find other libraries from source
set(EXTERNAL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")

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
file(GLOB YAGE_RENDER_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} yage/render/*.cpp)
file(GLOB YAGE_CURRENT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} yage/*.cpp)

set(YAGE_SOURCES
  ${YAGE_CORE_SOURCES}
  ${YAGE_PHYSICS_SOURCES}
  ${YAGE_MATH_SOURCES}
  ${YAGE_UTIL_SOURCES}
  ${YAGE_RENDER_SOURCES}
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

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/examples)

if(${YAGE_BUILD_TESTS})

  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)

endif(${YAGE_BUILD_TESTS})

if(${YAGE_BUILD_DOCS})

  find_package(Doxygen)

  if(DOXYGEN_FOUND)

    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile)
    
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("-- Configured Doxygen files")

    add_custom_target(doc_doxygen ALL
      COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT} >/dev/null
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      COMMENT "Generating API documentation with Doxygen")

  else(DOXYGEN_FOUND)

    message("Doxygen needs to be installed to generate the documentation.")

  endif(DOXYGEN_FOUND)
    
endif(${YAGE_BUILD_DOCS})
  
