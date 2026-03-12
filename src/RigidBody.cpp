#include "RigidBody.h"

RigidBody::RigidBody() = default;

RigidBody::RigidBody(const Mesh& mesh, glm::vec2 position, glm::vec2 size, glm::vec3 color) {
    this->mesh = mesh;
    this->size = size;
    this->color = color;

    this->position = position;
    this->lastPosition = position;
    this->velocity = glm::vec2(0, 0);
    this->lastVelocity = glm::vec2(0, 0);
}

void RigidBody::update(float delta) {
    lastPosition = position;
    lastVelocity = velocity;

    float deltaPositionY = lastVelocity.y * delta + 0.5f * 9.81f * delta*delta;

    position.y += deltaPositionY;
    velocity.y += 9.81f * delta;
}
