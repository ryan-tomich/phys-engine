#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Engine.h"
#include "Shader.h"

constexpr float VIRTUAL_WIDTH = 1600.0;
constexpr float VIRTUAL_HEIGHT = 900.0;
constexpr float ASPECT_RATIO = VIRTUAL_WIDTH / VIRTUAL_HEIGHT;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main() {
    if (!glfwInit()) {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(VIRTUAL_WIDTH, VIRTUAL_HEIGHT, "Unnamed Physics Engine", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    auto E = Engine(window);

    // test
    Mesh circle = Mesh::getCircleMesh(1, 20);
    Mesh rectangle = Mesh::getRectangleMesh();
    Mesh triangle = Mesh::getTriangleMesh();

    auto c1 = Body(circle, glm::vec2(100,100), glm::vec2(100, 100), glm::vec3(1,1,0));
    auto r1 = Body(rectangle, glm::vec2(700, 400), glm::vec2(200, 50), glm::vec3(0, 1, 1));
    auto t1 = Body(triangle, glm::vec2(1100, 30), glm::vec2(20, 100), glm::vec3(1,0,1));

    E.instantiate(c1);
    E.instantiate(r1);
    E.instantiate(t1);

    /* loop with fixed time steps and interpolation */
    constexpr float FIXED_DELTA = 1.0 / 60.0; // about 0.0167 seconds or 60Hz
    double lastTime = glfwGetTime();
    double accumulator = 0.0;

    while (!glfwWindowShouldClose(window)) {
        const double currentTime = glfwGetTime();
        double deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // prevent spiral of death from lag
        if (deltaTime > 0.25) {
            deltaTime = 0.25;
        }

        accumulator += deltaTime;

        glfwPollEvents();
        processInput(window);

        while (accumulator >= FIXED_DELTA) {
            E.update(FIXED_DELTA);
            accumulator -= FIXED_DELTA;
        }

        // fraction of time until next step
        const double alpha = accumulator / FIXED_DELTA;

        // I'll have to save previous and current positions of
        // objects in order to interpolate using alpha
        E.render(alpha);

        glfwSwapBuffers(window); // display the render
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void framebuffer_size_callback(GLFWwindow* window, const int width, const int height) {
    float aspectWidth;
    float aspectHeight;

    if (static_cast<float>(width) / static_cast<float>(height) > ASPECT_RATIO) {
        aspectHeight = static_cast<float>(height);
        aspectWidth = static_cast<float>(height) * ASPECT_RATIO;
    } else {
        aspectWidth = static_cast<float>(width);
        aspectHeight = static_cast<float>(width) / ASPECT_RATIO;
    }
    const float viewportX = (static_cast<float>(width) - aspectWidth) / 2;
    const float viewportY = (static_cast<float>(height) - aspectHeight) / 2;
    glViewport(static_cast<int>(viewportX), static_cast<int>(viewportY), static_cast<int>(aspectWidth), static_cast<int>(aspectHeight));
}
