cmake_minimum_required(VERSION 4.0)
project(learning_c C)

set(CMAKE_C_STANDARD 23)

include_directories(src)
include_directories(test)

add_executable(
        learning_c
        src/main.c
        src/helloworld/helloworld.c
        src/helloworld/helloworld.h
        src/memoryallocation/memory_allocation.c
        src/memoryallocation/memory_allocation.h
        src/string/string.c
        src/string/string.h
        src/arrays/arrays.c
        src/arrays/arrays.h

)
