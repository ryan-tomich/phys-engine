#include "Renderer.h"


void Renderer::draw(World world) {
    for (auto data : world.mesh_render_data) {
        //std::cout << data.transform.position.x;

        // interpolation???
        //auto p = glm::vec2(lastPosition + (position - lastPosition) * alpha);
    
        data.shader.use();
    
        auto model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(data.transform.position, 0.0f));
        model = glm::scale(model, glm::vec3(data.transform.size.x, data.transform.size.y, 1.0f));
    
        data.shader.setMatrix4("model", model);
        data.shader.setVector3f("spriteColor", data.color);
    
        glBindVertexArray(data.mesh.VAO);
        if (data.mesh.indexCount) {
            glDrawElements(GL_TRIANGLES, data.mesh.indexCount, GL_UNSIGNED_INT, nullptr);
        } else {
            //std::cout << "drawing using ";
            glDrawArrays(GL_TRIANGLES, 0, data.mesh.vertexCount);
        }
    }
}