#include "Body.h"

Body::Body() = default;

void Body::draw(float alpha, Renderer renderer) {
    auto p = glm::vec2(lastPosition + (position - lastPosition) * alpha);

    renderer.draw(mesh, color, p, size.x, size.y);
}

void Body::update(float delta) {}