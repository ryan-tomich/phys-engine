#ifndef README_MD_WORLD_H
#define README_MD_WORLD_H

#include <vector>

#include "MeshRenderData.h"
#include "RigidBody.h"
#include "Transform.h"


class World {
public:
    std::vector<Transform> transforms;
    std::vector<MeshRenderData> mesh_render_data;
    std::vector<RigidBody> rigid_bodies;
    // std::vector<StaticBody> static_bodies;
    // std::vector<CharacterBody> character_bodies;
};


#endif //README_MD_WORLD_H