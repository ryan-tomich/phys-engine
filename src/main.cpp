#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

//#include "Body.h"
#include "Renderer.h"
#include "Shader.h"

constexpr unsigned int WIN_WIDTH = 800;
constexpr unsigned int WIN_HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// temp
void processInput(GLFWwindow *window);
void render(double alpha, Shader s);
void update(float delta);

// temp
Renderer r;

// temp
//auto testBody = Body(glm::vec2(0, 0), glm::vec2(0, 0));

int main() {
    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }

    // need to research more about these hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "Hello World", nullptr, nullptr);
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

    // load and configure renderer
    const Shader s("../shaders/basic.vert", "../shaders/basic.frag");
    const glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(WIN_WIDTH),
        static_cast<float>(WIN_HEIGHT), 0.0f, -1.0f, 1.0f);
    s.use();
    s.setMatrix4("projection", projection);
    r = Renderer(s); // this will probably be used in a class like engine or something, instead of a global variable

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
        render(alpha, s);

        glfwSwapBuffers(window); // display the render
    }
    glfwTerminate();
    return 0;
}

// the render, update, and input functions will probably be moved to an Engine class
void render(double alpha, Shader s) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    r.draw(glm::vec2(100.0f, 200.0f),
        glm::vec2(300.0f, 400.0f),
        45.0f,
        glm::vec3(1.0f, 1.0f, 0.0f));
}

void update(const float delta) {
    //testBody.position += testBody.velocity * delta;
    // ...
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}