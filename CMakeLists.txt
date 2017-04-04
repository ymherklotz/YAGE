# zedengine library cmakelists.txt

project(YAGE)

# add sources to library
set(YAGE_SOURCES
  ${PROJECT_SOURCE_DIR}/src/camera2d.cpp
  ${PROJECT_SOURCE_DIR}/src/glslprogram.cpp
  ${PROJECT_SOURCE_DIR}/src/imageloader.cpp
  ${PROJECT_SOURCE_DIR}/src/iomanager.cpp
  ${PROJECT_SOURCE_DIR}/src/picopng.cpp
  ${PROJECT_SOURCE_DIR}/src/resourcemanager.cpp
  ${PROJECT_SOURCE_DIR}/src/sprite.cpp
  ${PROJECT_SOURCE_DIR}/src/texturecache.cpp
  ${PROJECT_SOURCE_DIR}/src/window.cpp)

# set include directory
include_directories(${YAGE_INCLUDE_DIRS}/YAGE/)

# make it a static library
add_library(${PROJECT_NAME} ${YAGE_SOURCES})
