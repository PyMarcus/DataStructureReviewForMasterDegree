cmake_minimum_required(VERSION 4.1)
project(datastructure C)

set(CMAKE_C_STANDARD 11)

add_executable(datastructure  src/main.c
        src/stack.c
        include/stack.h)
