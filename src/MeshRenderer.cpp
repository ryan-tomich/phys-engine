#include "MeshRenderer.h"


MeshRenderer::MeshRenderer(Mesh* mesh, glm::vec3 color, Transform* transform) {
    this->mesh = mesh;
    this->color = color;
    this->transform = transform;
}
