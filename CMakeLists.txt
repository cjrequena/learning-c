cmake_minimum_required(VERSION 4.0)
project(learning_c C)

set(CMAKE_C_STANDARD 23)

include_directories(src)
include_directories(test)

add_executable(
        learning_c
        src/main.c
        src/memory_allocation.c
)
