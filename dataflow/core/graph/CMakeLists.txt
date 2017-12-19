set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/test/graph)

set(STA_DEPS base ops)
add_executable(dataflow main.cc)
target_link_libraries(dataflow ${STA_DEPS})
