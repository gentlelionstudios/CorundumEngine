add_executable(engine
        main.cpp
        game.cpp ticks.cpp)
target_link_libraries(engine PRIVATE
        CONAN_PKG::sdl2 CONAN_PKG::glm CONAN_PKG::fmt)
