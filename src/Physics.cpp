//
// Created by ryant on 3/26/2026.
//

#include "Physics.h"

void Physics::update(World* world, float delta) {
    for (auto &body : world->rigid_bodies) {
        Transform* transform = &world->transforms[body.transform_index];

        body.update(transform, delta * SPEED, GRAVITY);
    }
}