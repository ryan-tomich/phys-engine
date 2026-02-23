#ifndef PHYS_TRIANGLE_H
#define PHYS_TRIANGLE_H

#include <array>

class Triangle {
public:
    explicit Triangle();
    void draw() const;

private:
    unsigned int VBO{}, VAO{};
};


#endif //PHYS_TRIANGLE_H