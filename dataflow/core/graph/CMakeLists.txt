set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/test/graph)

set(STA_DEPS base ops dataflow_proto protobuf)
add_executable(dataflow main.cc proto_parse.cc graph.cc udf_graph.cc)
target_link_libraries(dataflow ${STA_DEPS})
