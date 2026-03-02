#ifndef PHYS_RENDERER_H
#define PHYS_RENDERER_H
#include "Shader.h"
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/ext/matrix_transform.hpp"


class Renderer {
private:
    Shader shader = Shader();
    unsigned int quadVAO{};
    unsigned int triVAO{};
    unsigned int circleVAO{};

    void initQuadData();
    void initTriData();
    void initCircleData();

public:
    Renderer();
    explicit Renderer(const Shader &s);
    //~Renderer();

    void drawRect(glm::vec2 position, glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f)) const;
    void drawTriangle(glm::vec2 position, float base = 1.0f, float height = 1.0f, float rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f)) const;
    void drawCircle(glm::vec2 position, float radius = 1.0f, glm::vec3 color = glm::vec3(1.0f)) const;
};


#endif //PHYS_RENDERER_H