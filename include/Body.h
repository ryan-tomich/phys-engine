//
// Created by ryant on 2/24/2026.
//

#ifndef PHYS_BODY_H
#define PHYS_BODY_H

#include "glm/vec2.hpp"


struct Body {
public:
    glm::vec2 position{};
    glm::vec2 velocity{};

    Body();
    Body(glm::vec2 p, glm::vec2 v);
};


#endif //PHYS_BODY_H