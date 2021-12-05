cmake_minimum_required(VERSION 3.10)

# Compiler option
set(CMAKE_CXX_STANDARD 11)



add_executable(pentomino main.cpp piece.cpp)


add_library(libpentomino STATIC
    piece.cpp)