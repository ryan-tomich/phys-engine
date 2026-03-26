#include "MeshRenderData.h"


MeshRenderData::MeshRenderData(Mesh mesh, Shader shader, glm::vec3 color, Transform transform) {
    this->mesh = mesh;
    this->shader = shader;
    this->color = color;
    this->transform = transform;
}
