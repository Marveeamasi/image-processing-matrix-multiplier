cmake_minimum_required(VERSION 3.10)
project(matrix_multiplication)

set(CMAKE_CXX_STANDARD 11)

add_executable(matrix_multiplication main.cpp matrix_operations.cpp)
