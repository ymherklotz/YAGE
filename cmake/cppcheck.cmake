add_custom_target(
  cppcheck
  COMMAND cppcheck
  --enable=warning,performance,portability,information,missingInclude
  --std=c++11
  --library=${PROJECT_SOURCE_DIR}/cmake/sdl.cfg
  --template="[{severity}][{id}] {message} {callstack} \(On {file}:{line}\)"
  --verbose
  --quiet
  -I${PROJECT_SOURCE_DIR}
  -I${PROJECT_SOURCE_DIR}/yage
  -I${OPENGL_INCLUDE_DIR}
  -I${GLEW_INCLUDE_DIR}
  -i ${OPENGL_INCLUDE_DIR}
  -i ${GLEW_INCLUDE_DIR}
  ${PROJECT_SOURCE_DIR}/yage)
