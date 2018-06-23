/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: shader.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>

namespace yage
{

class Shader
{
public:
    Shader(std::string const &vertex_path, std::string const &fragment_path);
    Shader(const Shader &) = delete;
    Shader(Shader &&)      = delete;
    ~Shader();

    Shader &operator=(const Shader &) = delete;
    Shader &operator=(Shader &&) = delete;

    /// compiles vertex and fragment shader
    void use() const;

    /// set uniforms of different type
    void setUniform(std::string const &name, int value) const;
    void setUniform(std::string const &name, float value) const;
    void setUniform(std::string const &name, const glm::mat4 &matrix) const;

private:
    /// compiled shader program id
    GLuint program_id_ = 0;

    GLint getUniformLocation(std::string const &uniform_name) const;
    void errorCheck(GLuint shader, std::string const &shader_type) const;
};

} // namespace yage
