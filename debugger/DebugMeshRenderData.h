#ifndef README_MD_DEBUGMESHRENDERDATA_H
#define README_MD_DEBUGMESHRENDERDATA_H

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include "Mesh.h"

class DebugMeshRenderData {
public:
    DebugMeshRenderData(Mesh mesh, glm::vec2 position, glm::vec2 size, glm::vec3 color);

    Mesh mesh;
    glm::vec2 position{};
    glm::vec2 size{};
    glm::vec3 color{};
};


#endif //README_MD_DEBUGMESHRENDERDATA_H