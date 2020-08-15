cmake_minimum_required(VERSION 3.17)
project(Custom_Data)

set(CMAKE_CXX_STANDARD 14)

add_executable(Custom_Data main.cpp)

set_target_properties(
        Custom_Data PROPERTIES
        CXX_STANDARD 14
)


