#include "Body.h"

Body::Body() = default;

void Body::draw(float alpha) {
    auto p = glm::vec2(lastPosition + (position - lastPosition) * alpha);

    R.draw(mesh, color, p, size.x, size.y);
}

void Body::update(float delta, float gravity, float speed) {}