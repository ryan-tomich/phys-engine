#ifndef PHYS_INPUT_H
#define PHYS_INPUT_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

class Input {
public:
    Input();

    struct {
        bool left;
        bool right;
    } actions;

    static void keyCallback(GLFWwindow* window, int key, int, int action, int);

private:
    bool keys[1024] = {false};
};


#endif //PHYS_INPUT_H