#include "Body.h"

Body::Body() :  position(glm::vec2(0, 0)) , rotation(0) {
    velocity = glm::vec2(0, 0);
}

Body::Body(const glm::vec2 p, const glm::vec2 v, const float r) {
    position = p;
    velocity = v;
    rotation = r;
}
