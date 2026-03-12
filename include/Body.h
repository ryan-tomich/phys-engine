#ifndef PHYS_BODY_H
#define PHYS_BODY_H

#include <glm/vec2.hpp>
#include "Mesh.h"
#include "Renderer.h"


struct Body {
public:
    Body();

    void draw(float alpha);

    virtual void update(float delta, float gravity, float speed);
    virtual ~Body() = default;

    Renderer R;
    Mesh mesh;

    glm::vec2 size{};
    glm::vec3 color{};

    glm::vec2 position;
    glm::vec2 lastPosition;
    glm::vec2 velocity;
    glm::vec2 lastVelocity;

};


#endif //PHYS_BODY_H