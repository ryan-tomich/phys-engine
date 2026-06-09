#include "Transform.h"

//Transform::Transform() = default;

Transform::Transform(glm::vec2 size, glm::vec2 position) {
    this->size = size;
    this->position = position;

    this->last_size = size;
    this->last_position = position;
}
