#include "Input.h"

Input::Input() = default;

void Input::keyCallback(GLFWwindow* window, int key, int, int action, int) {
    Input* input = static_cast<Input*>(glfwGetWindowUserPointer(window));
    input->keys[key] = action == 2 || action == 1;

    if (input->keys[GLFW_KEY_ESCAPE]) {
        glfwSetWindowShouldClose(window, true);
    }

    input->actions.left = input->keys[GLFW_KEY_A] || input->keys[GLFW_KEY_LEFT];
    input->actions.right = input->keys[GLFW_KEY_D] || input->keys[GLFW_KEY_RIGHT];
}