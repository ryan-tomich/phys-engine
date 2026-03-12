#include "Engine.h"

Engine::Engine() : speed(1.0f)  {};

Engine::Engine(Renderer renderer, float speed) {
    this->renderer = renderer;
    this->speed = speed;

    rectangle = Mesh::getRectangleMesh();
    triangle = Mesh::getTriangleMesh();
    circle = Mesh:: getCircleMesh(1.0f, 20);
}

void Engine::render(float alpha) const {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for (const auto & body : world) {
        body->draw(alpha, renderer);
    }
}

void Engine::update(float delta) {
    for (auto & body : world) {
        body->update(delta * speed);
    }
}

void Engine::instantiate(std::unique_ptr<Body> b) {
    this->world.push_back(std::move(b));
}

void Engine::remove(std::unique_ptr<Body> b) {
    // search world for body and then remove it
}

void Engine::addTriangle(glm::vec2 position, glm::vec2 size, glm::vec3 color) {
    instantiate(std::make_unique<RigidBody>(triangle, position, size, color));
}

void Engine::addRect(glm::vec2 position, glm::vec2 size, glm::vec3 color) {
    instantiate(std::make_unique<RigidBody>(rectangle, position, size, color));
}

void Engine::addCircle(glm::vec2 position, glm::vec2 size, glm::vec3 color) {
    instantiate(std::make_unique<RigidBody>(circle, position, size, color));
}

void Engine::addCircle(float radius, int segments, glm::vec2 position, glm::vec2 size, glm::vec3 color) {
    instantiate(std::make_unique<RigidBody>(Mesh::getCircleMesh(radius, segments), position, size, color));
}
