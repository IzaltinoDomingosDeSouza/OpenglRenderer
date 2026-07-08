add_executable(demo game.cpp)

target_link_libraries(demo PRIVATE opengl_renderer)

target_include_directories(demo PRIVATE ${CMAKE_SOURCE_DIR}/src)