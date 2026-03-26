#include "Renderer.h"


Renderer::Renderer() = default;

Renderer::Renderer(const Shader& s) {
    shader = s;
}

void Renderer::draw(MeshRenderer m) {

    // interpolation???
    //auto p = glm::vec2(lastPosition + (position - lastPosition) * alpha);

    this->shader.use();

    auto model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(m.transform->position, 0.0f));
    model = glm::scale(model, glm::vec3(m.transform->size[0], m.transform->size[1], 1.0f));

    this->shader.setMatrix4("model", model);
    this->shader.setVector3f("spriteColor", m.color);

    glBindVertexArray(m.mesh->VAO);
    if (m.mesh->indexCount)
        glDrawElements(GL_TRIANGLES, m.mesh->indexCount, GL_UNSIGNED_INT, nullptr);
    else
        glDrawArrays(GL_TRIANGLES, 0, m.mesh->vertexCount);
}
