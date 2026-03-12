#ifndef PHYS_ENGINE_H
#define PHYS_ENGINE_H

#include <memory>
#include <GLFW/glfw3.h>
#include "Renderer.h"
#include "Body.h"
#include "RigidBody.h"


class Engine {
public:
    Engine();
    explicit Engine(Renderer renderer, float speed);

    void update(float delta);
    void render(float alpha) const;

    void instantiate(std::unique_ptr<Body> b);
    void remove(std::unique_ptr<Body> b);

    void addTriangle(glm::vec2 position, glm::vec2 size, glm::vec3 colo);
    void addRect(glm::vec2 position, glm::vec2 size, glm::vec3 color);
    void addCircle(glm::vec2 position, glm::vec2 size, glm::vec3 color);
    auto addCircle(float radius, int segments, glm::vec2 position, glm::vec2 size, glm::vec3 color) -> void;

private:
    Renderer renderer;
    float speed;

    std::vector<std::unique_ptr<Body>> world;

    Mesh triangle;
    Mesh rectangle;
    Mesh circle;
};


#endif //PHYS_ENGINE_H