#include "CollisionEngine.h"

void CollisionEngine::update(World* world,glm::vec2 position, glm::vec2 size) {
    detect(world, position, size);
    respond(world);
}

void CollisionEngine::detect(World* world, glm::vec2 position, glm::vec2 size) {
    Debugger::add_outline(Mesh::getRectangleMesh(), glm::vec2(800, 400), glm::vec2(50, 100), glm::vec3(1, 0, 0), 2);
    // use a quad tree
    // divide up to 3 or 4 times if transforms are present

    // check whether bounding box collides (basically just transform data)
    // specifically check candidates (figure out actual shape and check if they collided)

    // add collision_event to collisions
}

void CollisionEngine::respond(World* world) {
    // calculate response based on data from collisions

    // delete event from collisions

    // tell physics what to do to which transform
    // maybe I need a response object?

    // or maybe I could bypass this whole function and keep collisions in the world
    // then physics could respond to them and remove them

    // I'll start with detection and worry about this later
}

