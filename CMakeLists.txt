cmake_minimum_required(VERSION 3.24)
project(CorundumEngine)

set(CMAKE_CXX_STANDARD 20)

add_executable(CorundumEngine main.cpp ${Physics})

add_subdirectory(src)
add_subdirectory(dependencies)
add_subdirectory(testing)
