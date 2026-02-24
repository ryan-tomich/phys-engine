//
// Created by ryant on 2/24/2026.
//

#include "Body.h"

Body::Body() {
    position = glm::vec2(0,0);
    velocity = glm::vec2(0,0);
}

Body::Body(glm::vec2 p, glm::vec2 v) {
    position = p;
    velocity = v;
}