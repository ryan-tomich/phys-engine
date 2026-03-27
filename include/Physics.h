#ifndef README_MD_PHYSICS_H
#define README_MD_PHYSICS_H

#include "World.h"


class Physics {
public:
    static void update(World* world, float delta);
    static constexpr float GRAVITY = 9.81f;
    static constexpr float SPEED = 6.7f;
};


#endif //README_MD_PHYSICS_H