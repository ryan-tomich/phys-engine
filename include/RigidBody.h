#ifndef PHYS_RIGIDBODY_H
#define PHYS_RIGIDBODY_H

#include "Body.h"


class RigidBody : public Body {
public:
    RigidBody();
    RigidBody(const Mesh& m, glm::vec2 p, glm::vec2 s, glm::vec3 c, Renderer r);

    void update(float delta, float gravity, float speed) override;
};


#endif //PHYS_RIGIDBODY_H