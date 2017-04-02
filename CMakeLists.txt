# zedengine library cmakelists.txt

project(yage)

# add sources to library
set(YAGE_SOURCES ${PROJECT_SOURCE_DIR}/src/glsl_program.cpp
  ${PROJECT_SOURCE_DIR}/src/image_loader.cpp
  ${PROJECT_SOURCE_DIR}/src/io_manager.cpp
  ${PROJECT_SOURCE_DIR}/src/pico_png.cpp
  ${PROJECT_SOURCE_DIR}/src/resource_manager.cpp
  ${PROJECT_SOURCE_DIR}/src/sprite.cpp
  ${PROJECT_SOURCE_DIR}/src/texture_cache.cpp)

# set include directory
include_directories(${YAGE_INCLUDE_DIRS}/yage/)

# make it a static library
add_library(${PROJECT_NAME} ${YAGE_SOURCES})
