#include "Mesh.h"

Mesh Mesh::getRectangleMesh() {
    Mesh m;

    float vertices[] = {
        -0.5f,  0.5f,  // top-left
        -0.5f, -0.5f,  // bottom-left
         0.5f, -0.5f,  // bottom-right
         0.5f,  0.5f   // top-right
    };

    unsigned int indices[] = {
        0, 1, 2,  // first triangle
        0, 2, 3   // second triangle
    };

    glGenVertexArrays(1, &m.VAO);
    glGenBuffers(1, &m.VBO);
    glGenBuffers(1, &m.EBO);

    glBindVertexArray(m.VAO);

    glBindBuffer(GL_ARRAY_BUFFER, m.VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m.EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), static_cast<void*>(nullptr));
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    m.indexCount = 6;

    return m;
}

Mesh Mesh::getTriangleMesh() {
    Mesh m;

    constexpr float vertices[] = {
        0.0f,  0.5f,
       -0.5f, -0.5f,
        0.5f, -0.5f
   };

    glGenVertexArrays(1, &m.VAO);
    glGenBuffers(1, &m.VBO);

    glBindVertexArray(m.VAO);

    glBindBuffer(GL_ARRAY_BUFFER, m.VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), static_cast<void*>(nullptr));
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    m.vertexCount = 3;

    return m;
}

Mesh Mesh::getCircleMesh(float radius, int segments) {
    Mesh m;

    float angle = 360.0f / static_cast<float>(segments + 2);

    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> temp;

    for (int i = 0; i < segments + 2; i++) {
        float currentAngle = angle * i;
        float x = (radius/2) * cos(glm::radians(currentAngle));
        float y = (radius/2) * sin(glm::radians(currentAngle));
        float z = 0.0f;

        temp.push_back(glm::vec3(x, y, z));
    }

    for (int i = 0; i < segments; i++)
    {
        vertices.push_back(temp[0]);
        vertices.push_back(temp[i + 1]);
        vertices.push_back(temp[i + 2]);
    }

    glGenVertexArrays(1, &m.VAO);
    glGenBuffers(1, &m.VBO);

    glBindVertexArray(m.VAO);

    glBindBuffer(GL_ARRAY_BUFFER, m.VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), static_cast<void*>(nullptr));
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    m.vertexCount = vertices.size();

    return m;
}