cmake_minimum_required(VERSION 3.25)
project(CorundumEngine)

set(CMAKE_CXX_STANDARD 23)

add_executable(CorundumEngine main.cpp)

target_link_libraries(CorundumEngine Physics)

add_subdirectory(src)
add_subdirectory(dependencies)
add_subdirectory(testing)

