#include "Engine.h"

Engine::Engine() : gravity(9.81f), speed(5.0f) {}

Engine::Engine(float gravity, float speed) {
    this->gravity = gravity;
    this->speed = speed;
}

void Engine::render(float alpha) const {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // loop through `world` and render the objects according to their properties
    for (const auto & body : world) {
        body->draw(alpha);
    }
}

void Engine::update(float delta) {
    // I'll need to somehow detect collisions when they happen and use a

    // handle gravity
    for (auto & body : world) {
        body->update(delta, gravity, speed);
    }
}

void Engine::instantiate(std::unique_ptr<Body> b) {
    this->world.push_back(std::move(b));
}

void Engine::destroy(std::unique_ptr<Body> b) {
    // search world for body and then remove it
}