#ifndef GLSL_PROGRAM_HPP
#define GLSL_PROGRAM_HPP

#include <GL/glew.h>

#include <string>

class GlslProgram
{
private:
    // compiled shader program id
    GLuint program_id_ = 0;
    GLuint vertex_shader_id_ = 0;
    GLuint fragment_shader_id_ = 0;
    int attribute_index_ = 0;

    // compiles one shader
    void compileShader(const GLuint &shader, const std::string &file_path);
public:
    GlslProgram();
    ~GlslProgram();

    // compiles vertex and fragment shader
    void compileShaders(const std::string &vertex_shader_path, const std::string &fragment_shader_path);
    void linkShaders();
    void addAttribute(const std::string &attribute_name);
    GLint getUniformLocation(const std::string &uniform_name);
    void use();
    void unuse();
};


#endif
