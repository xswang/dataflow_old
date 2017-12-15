set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/test/base)

set(STA_DEPS base)
add_library(graph STATIC main.cc)
target_link_libraries(graph ${STA_DEPS})
#add_library(graph_shared SHARED main.cc)
