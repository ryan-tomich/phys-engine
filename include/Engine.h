#ifndef PHYS_ENGINE_H
#define PHYS_ENGINE_H

#include "Renderer.h"
#include <GLFW/glfw3.h>


class Engine {
public:
    explicit Engine(GLFWwindow *window);
    void update(float delta);
    void render(double alpha);

private:
    Renderer R;
    Mesh circle; // might store this differently when I have more shapes
    struct world{};
};


#endif //PHYS_ENGINE_H