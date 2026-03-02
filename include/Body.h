#ifndef PHYS_BODY_H
#define PHYS_BODY_H

#include <glm/vec2.hpp>


struct Body {
public:
    glm::vec2 position{};
    glm::vec2 size{};

    glm::vec2 velocity{};

    float rotation;

    Body();
    Body(glm::vec2 p, glm::vec2 v, float r);
};


#endif //PHYS_BODY_H