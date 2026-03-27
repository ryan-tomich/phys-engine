#ifndef README_MD_TRANSFORM_H
#define README_MD_TRANSFORM_H

#include <glm/vec2.hpp>


class Transform {
public:
    Transform();
    Transform(glm::vec2 size, glm::vec2 position);
    glm::vec2 size;
    glm::vec2 position;
    glm::vec2 last_size;
    glm::vec2 last_position;
};


#endif //README_MD_TRANSFORM_H