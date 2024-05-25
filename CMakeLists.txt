cmake_minimum_required(VERSION 3.28)
project(BookAdmin)

set(CMAKE_CXX_STANDARD 17)

add_executable(BookAdmin book.cpp
        BSTree.h
        program.h)
