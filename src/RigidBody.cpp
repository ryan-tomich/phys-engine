#include "RigidBody.h"


RigidBody::RigidBody() = default;

RigidBody::RigidBody(int transform_index) {
    this->transform_index = transform_index;
}

void RigidBody::update(Transform* transform, float delta, float gravity) {
    transform->last_position = transform->position;
    last_velocity = velocity;

    float delta_position_y = last_velocity.y * delta + 0.5f * gravity * delta * delta;

    transform->position.y += delta_position_y;

    velocity.y += gravity * delta;
}
