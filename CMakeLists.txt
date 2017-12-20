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
)

#file(GLOB_RECURSE dataflow_src ${PROJECT_SOURCE_DIR}/dataflow/*.*)
#foreach(src_file ${dataflow_src})
  #if("${src_file}" MATCHES "^${dataflow_src_dir}/.*\\.proto")
    #list(APPEND dataflow_pbfiles ${src_file})
    #endif()
  #endforeach()
#foreach(pb_file ${dataflow_pbfiles})
  #file(RELATIVE_PATH pb_relative_path_file ${PROJECT_SOURCE_DIR} ${pb_file})
  #list(APPEND dataflow_rel_pbfiles ${pb_relative_path_file})
  #endforeach()
#message(${dataflow_rel_pbfiles})

#RELATIVE_PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS
  #${PROJECT_SOURCE_DIR}
                               #  ${dataflow_rel_pbfiles})
                             #add_library(dataflow_proto ${PROTO_SRCS} ${PROTO_HDRS})

add_subdirectory(ps-lite)
add_subdirectory(dataflow/core/base)
add_subdirectory(dataflow/core/ops)
add_subdirectory(dataflow/core/graph)
add_subdirectory(dataflow/core/proto)
