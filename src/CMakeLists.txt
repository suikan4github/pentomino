add_executable(pentomino main.cpp piece.cpp)


add_library(libpentomino STATIC
    piece.cpp)