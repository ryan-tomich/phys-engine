#include "MeshRenderData.h"


MeshRenderData::MeshRenderData(Mesh mesh, Shader shader, glm::vec3 color, unsigned int transform_index) {
    this->mesh = mesh;
    this->shader = shader;
    this->color = color;
    this->transform_index = transform_index;
}
