cmake_minimum_required(VERSION 3.16)
project(CUnitTesting C)

set(CMAKE_C_STANDARD 11)

add_executable(CUnitTesting main.c avg_and_max.c avg_and_max.h)
target_link_libraries(CUnitTesting cunit)