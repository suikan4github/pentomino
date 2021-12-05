# 単体テストの定義
add_executable(test_pentomino test_all.cpp)
target_link_libraries(test_pentomino  
                        gtest_main
                        libpentomino
                 )

include(CTest)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.10.0
)

FetchContent_MakeAvailable(googletest)
                 
# Register the GoogleTest to CTest
include(GoogleTest)
gtest_discover_tests(test_pentomino)