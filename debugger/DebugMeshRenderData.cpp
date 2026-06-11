//
// Created by ryant on 6/11/2026.
//

#include "DebugMeshRenderData.h"

DebugMeshRenderData::DebugMeshRenderData(Mesh mesh, glm::vec2 position, glm::vec2 size, glm::vec3 color) {
    this->mesh = mesh;
    this->position = position;
    this->size = size;
    this->color = color;
}
