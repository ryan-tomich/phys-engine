cmake_minimum_required(VERSION 4.0)
project(phys)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(external/glfw)

add_executable(phys
        test/main.cpp
        external/glad/src/glad.c

        src/Engine.cpp
        include/Engine.h
        src/RigidBody.cpp
        include/RigidBody.h

        src/Transform.cpp
        include/Transform.h

        src/Renderer.cpp
        include/Renderer.h
        src/Shader.cpp
        include/Shader.h
        src/Mesh.cpp
        include/Mesh.h
        src/MeshRenderData.cpp
        include/MeshRenderData.h

        src/Input.cpp
        include/Input.h
        src/World.cpp
        include/World.h
        src/Physics.cpp
        include/Physics.h
)

target_include_directories(phys PRIVATE
        external
        include
        test/include
        external/glad/include
)

target_link_libraries(phys glfw opengl32 gdi32)