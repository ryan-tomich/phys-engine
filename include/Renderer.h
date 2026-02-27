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

    void initRenderData();


public:
    explicit Renderer(const Shader &s);
    Renderer();
    //~Renderer();

    void draw(glm::vec2 position,
        glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f,
        glm::vec3 color = glm::vec3(1.0f)) const;

};


#endif //PHYS_RENDERER_H