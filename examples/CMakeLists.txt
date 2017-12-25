function(make_example name)

  file(GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${name}/*.cpp)
  add_executable(${name} ${SOURCES})
  target_link_libraries(${name} yage)

endfunction(make_test)

make_example(simplegame)
make_example(shooter)
