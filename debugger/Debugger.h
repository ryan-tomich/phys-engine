#ifndef README_MD_DEBUGGER_H
#define README_MD_DEBUGGER_H

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include "Shader.h"
#include "Mesh.h"
#include "DebugMeshRenderData.h"

class Debugger {
public:
    static void draw(Shader* s);
    static void add_filled(Mesh mesh, glm::vec2 position, glm::vec2 size, glm::vec3 color);
    static void add_outline(Mesh mesh, glm::vec2 position, glm::vec2 size, glm::vec3 color, int width);
    inline static std::vector<DebugMeshRenderData> queue;
};


#endif //README_MD_DEBUGGER_H