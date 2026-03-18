cmake_minimum_required(VERSION 4.1)
project(datastructure C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(datastructure  src/main.c
        src/stack.c
        include/stack.h
        include/queue.h
        src/queue.c)
