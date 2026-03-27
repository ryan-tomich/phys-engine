#include "World.h"

#include "Engine.h"

World::World() = default;

void World::configure_shader(const char* vertex_path, const char* fragment_path) {
    global_shader = Shader(vertex_path, fragment_path);

    const glm::mat4 projection = glm::ortho(0.0f, (float)Engine::window_width, (float)Engine::window_height, 0.0f, -1.0f,1.0f);

    global_shader.use();
    global_shader.setMatrix4("projection", projection);
}

void World::add_rigid_body(Mesh mesh, glm::vec2 position, glm::vec2 size, glm::vec3 color) {
    transforms.emplace_back(size, position);
    unsigned int index = transforms.size() - 1;

    mesh_render_data.emplace_back(mesh, &global_shader, color, index);
    transforms[index].last_position = transforms[index].position; // to prevent initial lerping from (0,0) in Renderer.draw

    rigid_bodies.emplace_back(index);
}