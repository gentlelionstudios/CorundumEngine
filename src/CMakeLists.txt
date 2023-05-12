add_library(Physics SHARED
        Vector2.h
        Vector2.cpp
        )

target_link_libraries(CorundumEngine PUBLIC ${Physics})