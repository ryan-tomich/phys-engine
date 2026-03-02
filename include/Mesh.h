#ifndef PHYS_MESH_H
#define PHYS_MESH_H

#include <glad/glad.h>
#include <math.h>
#include <vector>
#include <glm/trigonometric.hpp>
#include <glm/vec3.hpp>


class Mesh {
public:
    unsigned int VBO{};
    unsigned int VAO{};
    unsigned int EBO{};

    int vertexCount{};
    int indexCount{};

    static Mesh getRectangleMesh();
    static Mesh getTriangleMesh();
    static Mesh getCircleMesh(float radius, int segments);
};


#endif //PHYS_MESH_H