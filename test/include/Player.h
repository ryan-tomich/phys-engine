#ifndef PHYS_PLAYER_H
#define PHYS_PLAYER_H
#include "CharacterBody.h"
#include "Input.h"


class Player : public CharacterBody {
public:
    explicit Player(GLFWwindow* window);
    void update(float delta) override;
private:
    GLFWwindow* window;
};


#endif //PHYS_PLAYER_H