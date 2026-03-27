#ifndef PHYS_RIGIDBODY_H
#define PHYS_RIGIDBODY_H

#include <glm/vec2.hpp>

#include "Transform.h"


class RigidBody {
public:
    RigidBody();
    explicit RigidBody(int transform_index);
    void update(Transform* transform, float delta, float gravity);

    int transform_index{};

    glm::vec2 velocity{};
    glm::vec2 last_velocity{};
};


#endif //PHYS_RIGIDBODY_H