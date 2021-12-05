cmake_minimum_required(VERSION 3.14)
project(pentomino VERSION 0.1.0)

set(CXX_STANDARD 11)

include(CTest)
enable_testing()





set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(src)
add_subdirectory(test)

include(FetchContent)

FetchContent_Declare(
  	googletest
  	GIT_REPOSITORY https://github.com/google/googletest.git
  	GIT_TAG release-1.10.0
)

FetchContent_MakeAvailable(googletest)
