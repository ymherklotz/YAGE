project(glad)

set(GLAD_SOURCES
  src/glad.c)

add_library(${PROJECT_NAME}
  ${GLAD_SOURCES})

target_include_directories(${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME})
