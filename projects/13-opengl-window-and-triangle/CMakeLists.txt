cmake_minimum_required(VERSION 3.20)

project(opengl_window_and_triangle C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

add_executable(opengl_window
    opengl-window.c
    external/glad/src/glad.c
)

target_include_directories(opengl_window PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/external/glad/include
)

target_link_libraries(opengl_window PRIVATE
    glfw
    OpenGL::GL
)
