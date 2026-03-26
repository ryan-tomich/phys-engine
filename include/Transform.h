#ifndef README_MD_TRANSFORM_H
#define README_MD_TRANSFORM_H

#include <glm/vec2.hpp>


class Transform {
public:
    Transform();
    Transform(glm::vec2 size, glm::vec2 position);
    glm::vec2 size;
    glm::vec2 position;

private:
    glm::vec2 lastPosition;
    glm::vec2 velocity;
    glm::vec2 lastVelocity;
};


#endif //README_MD_TRANSFORM_H