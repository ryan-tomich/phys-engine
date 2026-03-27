#include "Renderer.h"


void Renderer::draw(World* world, float alpha) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for (auto data : world->mesh_render_data) {
        Transform* transform = &world->transforms[data.transform_index];

        // interpolation
        auto position = glm::vec2(transform->last_position + (transform->position - transform->last_position) * alpha);
        //std::cout << position.y << "\n";

        data.shader.use();
    
        auto model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(position, 0.0f));
        model = glm::scale(model, glm::vec3(transform->size.x, transform->size.y, 1.0f));
    
        data.shader.setMatrix4("model", model);
        data.shader.setVector3f("spriteColor", data.color);
    
        glBindVertexArray(data.mesh.VAO);
        if (data.mesh.indexCount) {
            glDrawElements(GL_TRIANGLES, data.mesh.indexCount, GL_UNSIGNED_INT, nullptr);
        } else {
            glDrawArrays(GL_TRIANGLES, 0, data.mesh.vertexCount);
        }
    }
}