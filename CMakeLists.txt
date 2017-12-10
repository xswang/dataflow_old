# Minimun CMake required
cmake_minimum_required (VERSION 3.5)

# projectname is the same as the main-executable
project(dataflow)

add_definitions('-Wall -Wno-sign-compare -O3 -g -std=c++11 march=native -Wno-strict-aliasing -Wno-comment')
set(dataflow_cmake_dir ${PROJECT_SOURCE_DIR}/cmake)

include_directories(
  "{PROJECT_SOURCE_DIR}"
  "{PROJECT_BINARY_DIR}"
)

