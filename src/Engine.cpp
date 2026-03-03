#include "Engine.h"

Engine::Engine(GLFWwindow *window) {
    int width, height;
    glfwGetWindowSize(window, &width, &height);

    //this->circle = Mesh::getCircleMesh(1, 20);

    const glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f,1.0f);
    const Shader s("../shaders/basic.vert", "../shaders/basic.frag");

    s.use();
    s.setMatrix4("projection", projection);

    this->R = Renderer(s);
}

void Engine::render(double alpha) const {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // loop through `world` and render the objects according to their properties
    for (const auto & b : world) {
        Mesh m = b.mesh;
        auto c = b.color;
        glm::vec2 p = b.position;
        float w = b.size.x;
        float h = b.size.y;

        R.draw(m, c, p, w, h);
    }
}

void Engine::update(float delta) {
    // need to research how to handle collisions
    // ...

    // handle acceleration and positions
    for (auto & b : world) {
        b.lastPosition = b.position;
        b.lastVelocity = b.velocity;

        double deltaPY = b.lastVelocity.y * delta + 0.5 * GRAVITY * delta*delta;

        b.position.y += deltaPY;
        b.velocity.y += GRAVITY*delta;
    }
}

void Engine::instantiate(const Body& b) {
    this->world.push_back(b);
}

void Engine::destroy(const Body& b) {
    // ...
}
