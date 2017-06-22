cmake_minimum_required(VERSION 3.0)

# yage library cmakelists.txt
project(yage)

# set version numbers
set(YAGE_MAJOR_VERSION 0)
set(YAGE_MINOR_VERSION 1)
set(YAGE_PATCH_VERSION 2)
set(YAGE_VERSION
  ${YAGE_MAJOR_VERSION}.${YAGE_MINOR_VERSION}${YAGE_PATCH_VERSION})

# set standard
set(CMAKE_CXX_STANDARD 14)

if ( CMAKE_COMPILER_IS_GNUCC )
  set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif ( CMAKE_COMPILER_IS_GNUCC )
if ( MSVC )
  set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
endif ( MSVC )

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
  #  ${PROJECT_SOURCE_DIR}/src/vector2d.cpp
  ${PROJECT_SOURCE_DIR}/src/window.cpp)


# find libraries
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

# set include directory
include_directories(${YAGE_INCLUDE_DIR}
  ${YAGE_INCLUDE_DIR}/Physics/
  ${YAGE_INCLUDE_DIR}/Math/)

# make it a static library
add_library(${PROJECT_NAME} ${YAGE_SOURCES})

# add tests
add_executable(rigidbodytest
  ${YAGE_TEST_DIR}/rigidbodytest.cpp)
target_link_libraries(rigidbodytest
  ${YAGE_LIBRARIES}
  ${OPENGL_LIBRARIES}
  ${GLEW_LIBRARIES})

add_executable(matrixtest
  ${YAGE_TEST_DIR}/matrixtest.cpp)
target_link_libraries(matrixtest
  ${YAGE_LIBRARIES}
  ${OPENGL_LIBRARIES}
  ${GLEW_LIBRARIES})

# enable tests
enable_testing()
add_test(RigidBodyTest ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/rigidbodytest)
add_test(MatrixTest ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/matrixtest)
