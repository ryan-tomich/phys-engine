#ifndef README_MD_MESHRENDERDATA_H
#define README_MD_MESHRENDERDATA_H

#include "Mesh.h"
#include "Shader.h"
#include "Transform.h"


class MeshRenderData {
public:
    MeshRenderData(Mesh mesh, Shader shader, glm::vec3 color, Transform transform);
    Mesh mesh;
    Shader shader;
    glm::vec3 color;
    Transform transform;
};


#endif //README_MD_MESHRENDERDATA_H