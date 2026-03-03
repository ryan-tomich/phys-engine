#ifndef PHYS_ENGINE_H
#define PHYS_ENGINE_H

#include <GLFW/glfw3.h>
#include "Renderer.h"
#include "Body.h"


class Engine {
public:
    explicit Engine(GLFWwindow *window);
    void update(float delta);
    void render(double alpha) const;

    void instantiate(const Body& b);
    void destroy(const Body& b);

private:
    Renderer R;
    std::vector<Body> world;

    const double ARTIFICIAL_ACCELERATION = 40.0;
    const double GRAVITY = 9.81 * ARTIFICIAL_ACCELERATION;
};


#endif //PHYS_ENGINE_H