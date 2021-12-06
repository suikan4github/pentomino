
# Unit test
add_executable(${TEST_EXECUTABLE_NAME} test_all.cpp)
target_link_libraries(${TEST_EXECUTABLE_NAME}  
                        gtest_main
                        ${TEST_LIBRARY_NAME}
                 )


# Find and integrate the Google Test package

# Load the FetchContent module
# New in CMake 3.11
include(FetchContent)

# Declaration of googletest as content
FetchContent_Declare(
  	googletest
  	GIT_REPOSITORY https://github.com/google/googletest.git
  	GIT_TAG release-1.11.0
)

# Fetch the googletest
FetchContent_MakeAvailable(googletest)

# Include the GoogleTest
include(GoogleTest)

# Search test cases and link 
# New in CMake 3.10
gtest_discover_tests(${TEST_EXECUTABLE_NAME})