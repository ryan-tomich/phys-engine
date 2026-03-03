#include "Body.h"

Body::Body() = default;

Body::Body(const Mesh& m, const glm::vec2 p, const glm::vec2 s, glm::vec3 c) {
    mesh = m;
    size = s;
    color = c;

    position = p;
    lastPosition = p;
    velocity = glm::vec2(0, 0);
    lastVelocity = glm::vec2(0, 0);
}
