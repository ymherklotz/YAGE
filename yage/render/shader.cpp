/** ---------------------------------------------------------------------------
 * @file: shader.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "shader.h"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using std::runtime_error;

namespace yage
{

Shader::Shader(const std::string &vertex_path, const std::string &fragment_path)
{
    std::string vertex_source, fragment_source;
    std::ifstream vertex_file, fragment_file;

    vertex_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fragment_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        vertex_file.open(vertex_path);
        fragment_file.open(fragment_path);

        std::ostringstream vertex_stream, fragment_stream;
        vertex_stream << vertex_file.rdbuf();
        fragment_stream << fragment_file.rdbuf();

        vertex_file.close();
        fragment_file.close();

        vertex_source   = vertex_stream.str();
        fragment_source = fragment_stream.str();
    } catch (std::ifstream::failure e) {
        throw runtime_error("File could not be opened: " +
                            std::string(e.what()));
    }

    const char *vertex_source_c   = vertex_source.c_str();
    const char *fragment_source_c = fragment_source.c_str();

    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_source_c, NULL);
    glCompileShader(vertex_shader);
    errorCheck(vertex_shader, "vertex");

    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_source_c, NULL);
    glCompileShader(fragment_shader);
    errorCheck(fragment_shader, "fragment");

    program_id_ = glCreateProgram();
    glAttachShader(program_id_, vertex_shader);
    glAttachShader(program_id_, fragment_shader);
    glLinkProgram(program_id_);
    errorCheck(program_id_, "program");

    glDetachShader(program_id_, vertex_shader);
    glDetachShader(program_id_, fragment_shader);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

Shader::~Shader()
{
    /// cleans up all the shaders and the program
    if (program_id_ != 0) {
        glDeleteProgram(program_id_);
    }
}

void Shader::use() const
{
    glUseProgram(program_id_);
}

void Shader::setUniform(const std::string &name, int value) const
{
    glUniform1i(getUniformLocation(name), static_cast<GLint>(value));
}

void Shader::setUniform(const std::string &name, float value) const
{
    glUniform1f(getUniformLocation(name), static_cast<GLfloat>(value));
}

void Shader::setUniform(const std::string &name, const glm::mat4 &matrix) const
{
    glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &(matrix[0][0]));
}

GLint Shader::getUniformLocation(const std::string &uniform_name) const
{
    GLuint location = glGetUniformLocation(program_id_, uniform_name.c_str());
    if (location == GL_INVALID_INDEX) {
        throw std::runtime_error("'" + uniform_name + "' not found");
    }
    return location;
}

void Shader::errorCheck(GLuint shader, const std::string &shader_type) const
{
    int success;
    char info_log[1024];
    if (shader_type != std::string("program")) {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, NULL, info_log);
            throw runtime_error(shader_type +
                                " failed to compile: " + std::string(info_log));
        }
    } else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, NULL, info_log);
            throw runtime_error(shader_type +
                                " failed to link: " + std::string(info_log));
        }
    }
}

} // namespace yage
