# Minimun CMake required
cmake_minimum_required (VERSION 3.5)

# projectname is the same as the main-executable
project(dataflow)

add_definitions("-std=c++11")

set(dataflow_src_dir ${PROJECT_SOURCE_DIR}/dataflow)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(proto2cpp)

include_directories(
  "${PROJECT_SOURCE_DIR}/dataflow/"
  "${PROJECT_BINARY_DIR}/dataflow/"
)

link_directories(
  "${PROJECT_BINARY_DIR}/dataflow/core/base"
  "${PROJECT_BINARY_DIR}/dataflow/core/ops"
  "${PROJECT_BINARY_DIR}/dataflow/core/graph"
  "${PROJECT_BINARY_DIR}/dataflow/core/proto"
)

add_subdirectory(ps-lite)
add_subdirectory(dataflow/core/base)
add_subdirectory(dataflow/core/ops)
add_subdirectory(dataflow/core/graph)
add_subdirectory(dataflow/core/proto)
