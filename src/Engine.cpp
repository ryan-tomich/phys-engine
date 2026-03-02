#include "Engine.h"

Engine::Engine(GLFWwindow *window) {
    int width, height;
    glfwGetWindowSize(window, &width, &height);

    this->circle = Mesh::getCircleMesh(1, 20);

    const glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f,1.0f);
    const Shader s("../shaders/basic.vert", "../shaders/basic.frag");

    s.use();
    s.setMatrix4("projection", projection);

    this->R = Renderer(s);
}

void Engine::render(double alpha) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // loop through `world` and render the objects according to their properties
    R.draw(circle, glm::vec3(0,1,1), glm::vec2(1400,700), 200, 200);
}

void Engine::update(float delta) {
    // loop through `world` and update objects (what about collisions?)
    // I'll probably have to do some research
}