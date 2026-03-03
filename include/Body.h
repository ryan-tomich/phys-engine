#ifndef PHYS_BODY_H
#define PHYS_BODY_H

#include <glm/vec2.hpp>
#include "Mesh.h"


struct Body {
public:
    Mesh mesh;
    glm::vec2 size;
    float rotation;
    glm::vec3 color;

    glm::vec2 position;
    glm::vec2 lastPosition;
    glm::vec2 velocity;
    glm::vec2 lastVelocity;

    Body();
    Body(const Mesh& m, glm::vec2 p, glm::vec2 s, glm::vec3 c);
};


#endif //PHYS_BODY_H