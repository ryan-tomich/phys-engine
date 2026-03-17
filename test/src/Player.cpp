#include "../include/Player.h"

Player::Player(GLFWwindow* window) {
    this->window = window;
}

// ! currently not working !
// im thinking instead of player having an update function
// i'll add a characterBody to player and override that function
void Player::update(float delta) {
    std::cout << "player is updating";
    Input* input = static_cast<Input*>(glfwGetWindowUserPointer(window));
    // consider normalizing this
    if (input->actions.left) {
        std::cout << "moving left";
    }
    if (input->actions.right) {
        std::cout << "moving right";
    }

}
