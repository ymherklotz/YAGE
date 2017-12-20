/** ---------------------------------------------------------------------------
 * @file: glslprogram.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef GLSL_PROGRAM_H
#define GLSL_PROGRAM_H

#include <glad/glad.h>

#include <string>

namespace yage
{

class GlslProgram
{
public:
    GlslProgram() = default;
    GlslProgram(const GlslProgram &) = delete;
    GlslProgram(GlslProgram &&) = delete;
    ~GlslProgram();

    GlslProgram &operator=(const GlslProgram &) = delete;
    GlslProgram &operator=(GlslProgram &&) = delete;

    /// compiles vertex and fragment shader
    void compileShaders(const std::string &vertexShader,
                        const std::string fragmentShader);
    void compileShadersFromFile(const std::string &vertex_shader_path,
                                const std::string &fragment_shader_path);
    void linkShaders();
    void addAttribute(const std::string &attribute_name);
    GLint getUniformLocation(const std::string &uniform_name);
    void use();
    void unuse();

    void defaultSetup();

private:
    /// compiled shader program id
    GLuint program_id_ = 0;
    GLuint vertex_shader_id_ = 0;
    GLuint fragment_shader_id_ = 0;
    int attribute_index_ = 0;

    /// compiles one shader
    void compileShader(GLuint shader, const std::string &shaderContent);
    void compileShaderFromFile(GLuint shader, const std::string &file_path);
    void initShaderId();
};

} // namespace yage

#endif
