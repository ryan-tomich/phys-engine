#ifndef PHYS_SHADER_H
#define PHYS_SHADER_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "glm/fwd.hpp"
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/gtc/type_ptr.hpp"


class Shader {
public:
    unsigned int ID{};

    Shader();
    Shader(const char* vertexPath, const char* fragmentPath);

    void use() const;

    /*void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;*/
    void setFloat(const char* name, float value) const;
    void setInteger(const char* name, int value) const;
    void setVector2f(const char* name, float x, float y) const;
    void setVector2f(const char *name, const glm::vec2 &value) const;
    void setVector3f(const char* name, float x, float y, float z) const;
    void setVector3f(const char *name, const glm::vec3 &value) const;
    void setVector4f(const char* name, float x, float y, float z, float w) const;
    void setVector4f(const char *name, const glm::vec4 &value) const;
    void setMatrix4(const char *name, const glm::mat4 &matrix) const;
};


#endif //PHYS_SHADER_H