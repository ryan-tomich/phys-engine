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
    explicit Engine(float gravity, float speed);

    void update(float delta);
    void render(float alpha) const;

    void instantiate(std::unique_ptr<Body> b);
    void destroy(std::unique_ptr<Body> b);

    float gravity;
    float speed;

private:
    std::vector<std::unique_ptr<Body>> world;
};


#endif //PHYS_ENGINE_H