#include "Input.h"

Input::Input() = default;

void Input::keyCallback(GLFWwindow* window, int key, int, int action, int) {
    Input* input = static_cast<Input*>(glfwGetWindowUserPointer(window));
    input->keys[key] = action == 2 || action == 1 ? true : false;

    if (input->keys[GLFW_KEY_ESCAPE]) {
        glfwSetWindowShouldClose(window, true);
    }

    // could have a list with action names and their keys to loop through
    // then I could make a function for adding your own binds
    input->actions.left = input->keys[GLFW_KEY_A] || input->keys[GLFW_KEY_LEFT];
    input->actions.right = input->keys[GLFW_KEY_D] || input->keys[GLFW_KEY_RIGHT];
}