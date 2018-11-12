cmake_minimum_required(VERSION 3.12)
project(HW3_HEAP)

set(CMAKE_CXX_STANDARD 11)

file(GLOB HW3_HEAP_SRC
        "*.h"
        "*.cpp"
        )
add_executable(HW3_HEAP ${HW3_HEAP_SRC})
