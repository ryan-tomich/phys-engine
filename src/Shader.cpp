#include "Shader.h"

#include "glm/fwd.hpp"

Shader::Shader() = default;

std::string loadFile(const std::string& path) {
    const std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// may  need to edit this to support geometry shaders or whatever
Shader::Shader(const char* vertexPath, const char* fragmentPath) {
    // 1. retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    try {
        vertexCode = loadFile(vertexPath);
        fragmentCode = loadFile(fragmentPath);
    } catch(std::ifstream::failure e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
    }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    // 2. compile shaders
    int success;
    char infoLog[512];

    const unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };

    const unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    };

    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    // delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use() const {
    glUseProgram(ID);
}

void Shader::setFloat(const char *name, float value) const {
    glUniform1f(glGetUniformLocation(this->ID, name), value);
}
void Shader::setInteger(const char *name, int value) const {
    glUniform1i(glGetUniformLocation(this->ID, name), value);
}
void Shader::setVector2f(const char *name, float x, float y) const {
    glUniform2f(glGetUniformLocation(this->ID, name), x, y);
}
void Shader::setVector2f(const char *name, const glm::vec2 &value) const {
    glUniform2f(glGetUniformLocation(this->ID, name), value.x, value.y);
}
void Shader::setVector3f(const char *name, float x, float y, float z) const {
    glUniform3f(glGetUniformLocation(this->ID, name), x, y, z);
}
void Shader::setVector3f(const char *name, const glm::vec3 &value) const {
    glUniform3f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z);
}
void Shader::setVector4f(const char *name, float x, float y, float z, float w) const {
    glUniform4f(glGetUniformLocation(this->ID, name), x, y, z, w);
}
void Shader::setVector4f(const char *name, const glm::vec4 &value) const {
    glUniform4f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z, value.w);
}
void Shader::setMatrix4(const char *name, const glm::mat4 &matrix) const {
    glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, false, glm::value_ptr(matrix));
}
