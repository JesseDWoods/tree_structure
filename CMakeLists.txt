cmake_minimum_required(VERSION 4.2)
project(tree_structure C)

set(CMAKE_C_STANDARD 23)

add_executable(tree_structure main.c
        tree.c
        tree.h)
