include (ExternalProject)

set(EIGEN_INCLUDE_DIR ${THIRD_PARTY_DIR}/eigen/include)
set(EIGEN_LIBRARY_DIR ${THIRD_PARTY_DIR}/eigen/lib)

set(eigen_HEADERS_DIR ${CMAKE_CURRENT_BINARY_DIR}/eigen/src/eigen/include)
set(eigen_URL https://github.com/eigenteam/eigen-git-mirror.git)
set(eigen_TAG 11a3c93ee327dd2be34bc56bc04a5ebcb3340256)

set(EIGEN_BUILD_LIBRARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/eigen/src/eigen)
set(EIGEN_LIBRARY_NAMES libeigen.a)

foreach(LIBRARY_NAME ${EIGEN_LIBRARY_NAMES})
  list(APPEND EIGEN_STATIC_LIBRARIES ${EIGEN_LIBRARY_DIR}/${LIBRARY_NAME})
  list(APPEND EIGEN_BUILD_STATIC_LIBRARIES ${EIGEN_BUILD_LIBRARY_DIR}/${LIBRARY_NAME})
endforeach()

ExternalProject_Add(eigen
    PREFIX eigen
    GIT_REPOSITORY ${eigen_URL}
    GIT_TAG ${eigen_TAG}
    CMAKE_CACHE_ARGS
        -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS:BOOL=OFF
        -DCMAKE_CXX_FLAGS:STRING=${CMAKE_CXX_FLAGS}
        -DCMAKE_CXX_FLAGS_DEBUG:STRING=${CMAKE_CXX_FLAGS_DEBUG}
        -DCMAKE_CXX_FLAGS_RELEASE:STRING=${CMAKE_CXX_FLAGS_RELEASE}
        -DBUILD_TESTING:BOOL=OFF
        -DWITH_GFLAGS:BOOL=OFF
)


add_custom_target(eigen_create_header_dir
  COMMAND ${CMAKE_COMMAND} -E make_directory ${EIGEN_INCLUDE_DIR}/eigen
  DEPENDS eigen)

add_custom_target(eigen_copy_headers_to_destination
  DEPENDS eigen_create_header_dir)

foreach(header_file ${eigen_HEADERS_DIR})
  add_custom_command(TARGET eigen_copy_headers_to_destination PRE_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different ${header_file} ${EIGEN_INCLUDE_DIR}/eigen)
endforeach()
