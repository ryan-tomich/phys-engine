#include "Renderer.h"

Renderer::Renderer() = default;

Renderer::Renderer(const Shader& s) {
    shader = s;
}

void Renderer::draw(const Mesh& m, const glm::vec3 color, const glm::vec2 position, const float width, const float height) const {

    this->shader.use();

    auto model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position, 0.0f));
    model = glm::scale(model, glm::vec3(width, height, 1.0f));

    this->shader.setMatrix4("model", model);
    this->shader.setVector3f("spriteColor", color);

    glBindVertexArray(m.VAO);
    if (m.indexCount)
        glDrawElements(GL_TRIANGLES, m.indexCount, GL_UNSIGNED_INT, 0);
    else
        glDrawArrays(GL_TRIANGLES, 0, m.vertexCount);
}
