#ifndef PHYS_RENDERER_H
#define PHYS_RENDERER_H

#include "Mesh.h"
#include "Shader.h"
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/ext/matrix_transform.hpp>


class Renderer {
private:
    Shader shader = Shader();

public:
    Renderer();
    explicit Renderer(const Shader &s);
    void draw(const Mesh& m, glm::vec3 color, glm::vec2 position, float width, float height) const;
};


#endif //PHYS_RENDERER_H