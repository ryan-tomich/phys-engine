#ifndef PHYS_RENDERER_H
#define PHYS_RENDERER_H

#include "Shader.h"
#include "MeshRenderer.h"
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/ext/matrix_transform.hpp>


class Renderer {
private:
    Shader shader = Shader();

public:
    Renderer();
    explicit Renderer(const Shader &s);
    void draw(MeshRenderer m);
};


#endif //PHYS_RENDERER_H