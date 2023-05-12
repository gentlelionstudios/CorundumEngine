set(TestLib vector_tests.cpp)

add_executable(Tests ${TestLib})

target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain Physics)
target_include_directories(Tests PRIVATE ../src)