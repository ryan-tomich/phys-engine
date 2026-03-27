#ifndef PHYS_ENGINE_H
#define PHYS_ENGINE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Input.h"
#include "Physics.h"
#include "Renderer.h"
#include "World.h"
#include "Mesh.h"


class Engine {
public:
    Engine();

    int start();
    void loop(GLFWwindow* window);

    constexpr static int window_width = 1600;
    constexpr static int window_height = 900;
    constexpr static float aspect_ratio = (float)window_width / window_height;

private:
    World world;
    Input input;

    constexpr static float FIXED_DELTA = 1.0f / 60.0f;
    float last_time;
    float accumulator;

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

    void test_function();
};


#endif //PHYS_ENGINE_H