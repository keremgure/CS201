cmake_minimum_required(VERSION 3.12)
project(HW3)

set(CMAKE_CXX_STANDARD 11)

file(GLOB HW3_SRC
        "*.h"
        "*.cpp"
        )

add_executable(HW3 ${HW3_SRC})