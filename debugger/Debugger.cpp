#include "Debugger.h"

void Debugger::draw(Shader* s) {
    for (auto data : queue) {
        s->use();
        auto model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(data.position, 0.0f));
        model = glm::scale(model, glm::vec3(data.size.x, data.size.y, 1.0f));

        s->setMatrix4("model", model);
        s->setVector3f("spriteColor", data.color);

        glBindVertexArray(data.mesh.VAO);
        if (data.mesh.indexCount) {
            glDrawElements(GL_TRIANGLES, data.mesh.indexCount, GL_UNSIGNED_INT, nullptr);
        } else {
            glDrawArrays(GL_TRIANGLES, 0, data.mesh.vertexCount);
        }
    }
}

void Debugger::add_filled(Mesh mesh, glm::vec2 position, glm::vec2 size, glm::vec3 color) {
    queue.emplace_back(mesh, position, size, color);
}

void Debugger::add_outline(Mesh mesh, glm::vec2 position, glm::vec2 size, glm::vec3 color, int width) {
    queue.emplace_back(mesh, position, size, color);
    queue.emplace_back(mesh, position, size - glm::vec2(width*2, width*2), glm::vec3(0, 0, 0));
}