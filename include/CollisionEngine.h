#ifndef README_MD_COLLISIONS_H
#define README_MD_COLLISIONS_H

#include <GLFW/glfw3.h>
#include "Engine.h"
#include "World.h"
#include "CollisionEvent.h"

class CollisionEngine {
public:
    static void update(World* world, glm::vec2 position, glm::vec2 size);
private:
    static void detect(World* world, glm::vec2 position, glm::vec2 size);
    static void respond(World* world);

    std::vector<CollisionEvent> collisions;
};


#endif //README_MD_COLLISIONS_H