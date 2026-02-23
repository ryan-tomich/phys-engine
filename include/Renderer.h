#ifndef PHYS_RENDERER_H
#define PHYS_RENDERER_H


class Renderer {
    unsigned int shaderProgram;

public:
    Renderer();
    void render(double alpha) const;
};


#endif //PHYS_RENDERER_H