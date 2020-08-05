cmake_minimum_required(VERSION 3.17)
project(corundum VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif ()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_add_remote(
        NAME
        bincrafters
        URL
        https://api.bintray.com/conan/bincrafters/public-conan)

conan_cmake_run(
        REQUIRES
        doctest/[>=2.4.0]
        fmt/7.0.2
        glm/0.9.9.8
        libpng/1.6.37
        zlib/1.2.11
        bzip2/1.0.8
        sdl2/2.0.12@bincrafters/stable
        sdl2_mixer/2.0.4@bincrafters/stable
        sdl2_image/2.0.5@bincrafters/stable
        sdl2_ttf/2.0.15@bincrafters/stable
        BASIC_SETUP CMAKE_TARGETS
        BUILD missing)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)