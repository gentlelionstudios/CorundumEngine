add_library(coreLib "")

add_subdirectory(components)

target_sources(coreLib
        PRIVATE
        ticks.cpp ticks.h
        game.cpp game.h
        component.h
        entity.cpp entity.h
        entity_manager.cpp entity_manager.h
        )

target_link_libraries(coreLib
        PRIVATE
        CONAN_PKG::sdl2
        CONAN_PKG::glm
        CONAN_PKG::fmt)

add_executable(engine main.cpp)
target_link_libraries(engine
        PRIVATE
        coreLib
        CONAN_PKG::sdl2
        CONAN_PKG::glm
        CONAN_PKG::fmt)
