cmake_minimum_required(VERSION 4.0)
project(phys)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(external/glfw)

add_executable(phys
        src/main.cpp
        external/glad/src/glad.c
)

target_include_directories(phys PRIVATE
        external/glad/include
        /external
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(phys glfw opengl32 gdi32)