#ifndef README_MD_MESHRENDERER_H
#define README_MD_MESHRENDERER_H

#include "Mesh.h"
#include "Transform.h"


class MeshRenderer {
public:
    MeshRenderer(Mesh* mesh, glm::vec3 color, Transform* transform);
    Mesh* mesh;
    glm::vec3 color;
    Transform* transform;
};


#endif //README_MD_MESHRENDERER_H