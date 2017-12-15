# Minimun CMake required
cmake_minimum_required (VERSION 3.5)

# projectname is the same as the main-executable
project(dataflow)

add_definitions("-std=c++11")

include_directories(
  "{PROJECT_SOURCE_DIR}"
  "{PROJECT_BINARY_DIR}"
)


add_subdirectory("dataflow/core/base")
