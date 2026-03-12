#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Engine.h"
#include "Shader.h"
#include "Input.h"
#include "RigidBody.h"

constexpr float WIDTH = 900.0f;
constexpr float HEIGHT = 1200.0f;
constexpr float ASPECT_RATIO = WIDTH / HEIGHT;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main() {
    // initialize glfw window
    if (!glfwInit()) {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Unnamed Physics Engine", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // enable vsync
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // initialize input
    Input input;
    glfwSetWindowUserPointer(window, &input);
    glfwSetKeyCallback(window, Input::keyCallback);

    // initialize glad
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // initialize Renderer & Engine
    const glm::mat4 projection = glm::ortho(0.0f, WIDTH, HEIGHT, 0.0f, -1.0f,1.0f);
    const Shader s("../shaders/basic.vert", "../shaders/basic.frag");
    s.use();
    s.setMatrix4("projection", projection);

    auto R = Renderer(s);
    auto E = Engine(R, 5.0f);

    E.addCircle(glm::vec2(100,100), glm::vec2(100,100), glm::vec3(0,1,1));
    E.addRect(glm::vec2(250, 100), glm::vec2(100, 100), glm::vec3(1, 1, 0));
    E.addTriangle(glm::vec2(400, 100), glm::vec2(100, 100), glm::vec3(1, 0, 1));

    // loop with fixed time steps and interpolation
    constexpr float FIXED_DELTA = 1.0f / 60.0f; // about 0.0167 seconds or 60Hz
    float lastTime = glfwGetTime();
    float accumulator = 0.0f;

    while (!glfwWindowShouldClose(window)) {
        const float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // prevent spiral of death from lag
        if (deltaTime > 0.25f) {
            deltaTime = 0.25f;
        }

        accumulator += deltaTime;

        glfwPollEvents();
        //some type of processInput()? maybe for the player

        while (accumulator >= FIXED_DELTA) {
            E.update(FIXED_DELTA);
            accumulator -= FIXED_DELTA;
        }

        // fraction of time until next step
        const float alpha = accumulator / FIXED_DELTA;

        // I'll have to save previous and current positions of
        // objects in order to interpolate using alpha
        E.render(alpha);

        glfwSwapBuffers(window); // display the render
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    float aspectWidth;
    float aspectHeight;

    if ((float)width / (float)height > ASPECT_RATIO) {
        aspectHeight = (float)height;
        aspectWidth = (float)height * ASPECT_RATIO;
    } else {
        aspectWidth = (float)width;
        aspectHeight = (float)width / ASPECT_RATIO;
    }
    float viewportX = ((float)width - aspectWidth) / 2.0f;
    float viewportY = ((float)height - aspectHeight) / 2.0f;
    glViewport((int)viewportX, (int)viewportY, (int)aspectWidth, (int)aspectHeight);
}