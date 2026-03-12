#ifndef PHYS_CHARACTERBODY_H
#define PHYS_CHARACTERBODY_H

#include "Body.h"


class CharacterBody : public Body {
public:
    CharacterBody();
    CharacterBody(const Mesh& m, glm::vec2 p, glm::vec2 s, glm::vec3 c);

    void update(float delta) override;
};


#endif //PHYS_CHARACTERBODY_H