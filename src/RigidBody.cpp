#include "RigidBody.h"

RigidBody::RigidBody() = default;

RigidBody::RigidBody(const Mesh& mesh, glm::vec2 position, glm::vec2 size, glm::vec3 color, Renderer renderer) {
    this->mesh = mesh;
    this->size = size;
    this->color = color;

    this->position = position;
    this->lastPosition = position;
    this->velocity = glm::vec2(0, 0);
    this->lastVelocity = glm::vec2(0, 0);

    this->R = renderer;
}

void RigidBody::update(float delta, float gravity, float speed) {
    lastPosition = position;
    lastVelocity = velocity;

    float deltaPositionY = lastVelocity.y * delta + 0.5f * gravity * delta*delta;

    position.y += deltaPositionY * speed;
    velocity.y += gravity * delta * speed;
}

