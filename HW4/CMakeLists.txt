cmake_minimum_required(VERSION 3.12)
project(HW4)

set(CMAKE_CXX_STANDARD 11)

file(GLOB HW4_SRC
        "*.h"
        "*.cpp"
        )

add_executable(HW4 ${HW4_SRC})