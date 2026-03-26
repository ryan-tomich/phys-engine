#ifndef PHYS_RENDERER_H
#define PHYS_RENDERER_H

#include "Shader.h"
#include "MeshRenderData.h"
#include "World.h"


class Renderer {
public:
    static void draw(World world);
};


#endif //PHYS_RENDERER_H