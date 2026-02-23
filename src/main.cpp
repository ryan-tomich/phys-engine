#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Engine.h"
#include "Renderer.h"

void framebuffer_size_callback(GLFWwindow* window, const int width, const int height) {
        // sets the viewport area on resize
        glViewport(0, 0, width, height);
}

int main() {
    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    /* Initialize GLAD */
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    /* Initialize Engine */
    auto e = Engine();

    /* Initialize Renderer */
    const auto r = Renderer();

    /* loop with fixed time steps and interpolation */
    constexpr double fixedDelta = 1.0 / 60.0; // about 0.0167 seconds or 60Hz
    double lastTime = glfwGetTime();
    double accumulator = 0.0;

    while (!glfwWindowShouldClose(window)) {
        const double currentTime = glfwGetTime();
        double deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // prevent spiral of death
        if (deltaTime > 0.25) {
            deltaTime = 0.25;
        }

        accumulator += deltaTime;

        glfwPollEvents();
        // processInput()?

        while (accumulator >= fixedDelta) {
            e.update(fixedDelta);
            accumulator -= fixedDelta;
        }

        // fraction of time until next step
        const double alpha = accumulator / fixedDelta;

        // I'll have to save previous and current positions of
        // objects in order to interpolate using alpha
        r.render(alpha);
        glfwSwapBuffers(window); // display the render
    }
    glfwTerminate();
    return 0;
}
