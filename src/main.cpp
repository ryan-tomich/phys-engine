#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "Renderer.h"
#include "Shader.h"
#include "Mesh.h"

constexpr float VIRTUAL_WIDTH = 1600.0;
constexpr float VIRTUAL_HEIGHT = 900.0;
constexpr float ASPECT_RATIO = VIRTUAL_WIDTH / VIRTUAL_HEIGHT;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// temp
void processInput(GLFWwindow *window);
void render(double alpha);
void update(float delta);

// temp
Renderer r;

// temp
Mesh triangle;
Mesh rectangle;
Mesh circle;

int main() {
    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }

    // need to research more about these hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(VIRTUAL_WIDTH, VIRTUAL_HEIGHT, "Hello World", nullptr, nullptr);
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

    // load and configure temporary renderer
    const glm::mat4 projection = glm::ortho(0.0f, VIRTUAL_WIDTH, VIRTUAL_HEIGHT, 0.0f, -1.0f, 1.0f);
    const Shader s("../shaders/basic.vert", "../shaders/basic.frag");
    s.use();
    s.setMatrix4("projection", projection);
    r = Renderer(s);

    // temp
    triangle = Mesh::getTriangleMesh();
    rectangle = Mesh::getRectangleMesh();
    circle = Mesh::getCircleMesh(1, 20);

    /* loop with fixed time steps and interpolation */
    constexpr float fixedDelta = 1.0 / 60.0; // about 0.0167 seconds or 60Hz
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

        while (accumulator >= fixedDelta) {
            update(fixedDelta);
            accumulator -= fixedDelta;
        }

        // fraction of time until next step
        const double alpha = accumulator / fixedDelta;

        // I'll have to save previous and current positions of
        // objects in order to interpolate using alpha
        render(alpha);

        glfwSwapBuffers(window); // display the render
    }
    glfwTerminate();
    return 0;
}

void render(double alpha) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    r.draw(triangle, glm::vec3(0,1,1), glm::vec2(100.0f, 100.0f), 100.0f, 100.0f);
    r.draw(rectangle, glm::vec3(1, 1, 0), glm::vec2(750, 400), 200.0f, 200.0f);
    r.draw(circle, glm::vec3(1,0,1), glm::vec2(1400,700), 200, 200);
}

void update(const float delta) {
    // ...
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
