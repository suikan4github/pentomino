cmake_minimum_required(VERSION 3.14)
project(pentomino VERSION 0.1.0)

# Parameters inside project
set(TEST_EXECUTABLE_NAME test_${PROJECT_NAME})
set(EXECUTABLE_NAME ${PROJECT_NAME})
set(TEST_LIBRARY_NAME lib${PROJECT_NAME})


set(CXX_STANDARD 11)

include(CTest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(src)
add_subdirectory(test)

