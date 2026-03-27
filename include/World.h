#ifndef README_MD_WORLD_H
#define README_MD_WORLD_H

#include <vector>

#include "MeshRenderData.h"
#include "RigidBody.h"
#include "Transform.h"


class World {
public:
    World();
    void add_rigid_body(Mesh mesh, glm::vec2 position, glm::vec2 size, glm::vec3 color);
    //void add_rigid_body(Mesh mesh, glm::vec2 position, glm::vec2 size, glm::vec3 color, Shader* custom_shader);

    Shader global_shader;
    void configure_shader(const char* vertex_path, const char* fragment_path);

    std::vector<Transform> transforms;
    std::vector<MeshRenderData> mesh_render_data;
    std::vector<RigidBody> rigid_bodies;
    // std::vector<StaticBody> static_bodies;
    // std::vector<CharacterBody> character_bodies;
};


#endif //README_MD_WORLD_H