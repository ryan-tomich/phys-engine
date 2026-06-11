cmake_minimum_required(VERSION 4.0)
project(phys)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(external/glfw)

add_executable(phys
        test/main.cpp
        external/glad/src/glad.c

        src/Engine.cpp
        include/Engine.h
        src/World.cpp
        include/World.h
        src/Physics.cpp
        include/Physics.h

        src/CollisionEngine.cpp
        include/CollisionEngine.h
        src/CollisionEvent.cpp
        include/CollisionEvent.h

        src/StaticBody.cpp
        include/StaticBody.h
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

        debugger/Debugger.cpp
        debugger/Debugger.h
        debugger/DebugMeshRenderData.cpp
        debugger/DebugMeshRenderData.h
)

target_include_directories(phys PRIVATE
        external
        include
        test/include
        external/glad/include
)

target_link_libraries(phys glfw opengl32 gdi32)