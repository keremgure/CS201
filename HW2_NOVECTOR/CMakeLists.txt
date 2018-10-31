cmake_minimum_required(VERSION 3.12)
project(HW2)

set(CMAKE_CXX_STANDARD 11)

file(GLOB HW2_SRC
        "*.h"
        "*.cpp"
        )
add_executable(HW2 ${HW2_SRC})
