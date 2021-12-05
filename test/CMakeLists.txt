cmake_minimum_required(VERSION 3.1.0)
set(CXX_STANDARD 11)


# Down load GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)


# 単体テストの定義
add_executable(test_pentomino test_all.cpp)
target_link_libraries(test_pentomino  
                        gtest_main
                        libpentomino
                 )

# CTestへ単体テストを登録
include(GoogleTest)
gtest_discover_tests(test_pentomino)