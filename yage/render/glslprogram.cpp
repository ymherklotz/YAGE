/** ---------------------------------------------------------------------------
 * @file: glslprogram.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "glslprogram.h"

#include <fstream>
#include <stdexcept>
#include <vector>

namespace yage
{

GlslProgram::~GlslProgram()
{
    /// cleans up all the shaders and the program
    if (fragment_shader_id_ != 0) {
        glDeleteShader(fragment_shader_id_);
    }

    if (vertex_shader_id_ != 0) {
        glDeleteShader(vertex_shader_id_);
    }

    if (program_id_ != 0) {
        glDeleteProgram(program_id_);
    }
}

void GlslProgram::compileShader(GLuint shader, const std::string &shaderContent)
{
    // cast source to a c string to get the address of it and input it for
    // compilation
    const auto *vertex_source = (const GLchar *)shaderContent.c_str();
    glShaderSource(shader, 1, &vertex_source, nullptr);
    glCompileShader(shader);

    // check if compilation was successful
    GLint is_compiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, (int *)&is_compiled);

    // if it isn't compiled throw exception to clean up
    if (is_compiled == GL_FALSE) {
        GLint max_length = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &max_length);

        std::vector<GLchar> error_log(max_length);
        glGetShaderInfoLog(shader, max_length, &max_length, &error_log[0]);
        std::string error_log_str((const char *)&error_log[0]);

        std::string shaderName;
        if (shader == vertex_shader_id_)
            shaderName = "vertex shader";
        else
            shaderName = "fragment shader";

        throw std::runtime_error("Couldn't compile the " + shaderName + " : " +
                                 error_log_str);
    }
}

void GlslProgram::compileShaderFromFile(GLuint shader,
                                        const std::string &file_path)
{
    // get a string with the input from the shader file
    std::ifstream file(file_path);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open '" + file_path + "'");
    }

    std::string content = "";
    std::string line;

    while (std::getline(file, line)) {
        content += line + "\n";
    }
    file.close();

    compileShader(shader, content);
}

void GlslProgram::initShaderId()
{
    // create the program that will be run on GPU
    program_id_ = glCreateProgram();

    // create vertex shader
    vertex_shader_id_ = glCreateShader(GL_VERTEX_SHADER);
    if (vertex_shader_id_ == 0) {
        throw std::runtime_error("Vertex shader failed to be created");
    }

    // create fragment shader
    fragment_shader_id_ = glCreateShader(GL_FRAGMENT_SHADER);
    if (fragment_shader_id_ == 0) {
        throw std::runtime_error("Fragment shader failed to be created");
    }
}

void GlslProgram::compileShaders(const std::string &vertexShader,
                                 const std::string fragmentShader)
{
    initShaderId();

    compileShader(vertex_shader_id_, vertexShader);
    compileShader(fragment_shader_id_, fragmentShader);
}

void GlslProgram::compileShadersFromFile(
    const std::string &vertex_shader_path,
    const std::string &fragment_shader_path)
{
    initShaderId();

    // compile the two shaders
    compileShaderFromFile(vertex_shader_id_, vertex_shader_path);
    compileShaderFromFile(fragment_shader_id_, fragment_shader_path);
}

void GlslProgram::linkShaders()
{
    // attach the shaders that we want
    glAttachShader(program_id_, vertex_shader_id_);
    glAttachShader(program_id_, fragment_shader_id_);

    // link our program
    glLinkProgram(program_id_);

    GLint is_linked = 0;
    glGetProgramiv(program_id_, GL_LINK_STATUS, (int *)&is_linked);
    if (is_linked == GL_FALSE) {
        GLint max_length = 0;
        glGetProgramiv(program_id_, GL_INFO_LOG_LENGTH, &max_length);

        std::vector<GLchar> error_log(max_length);
        glGetProgramInfoLog(program_id_, max_length, &max_length,
                            &error_log[0]);

        std::string error_log_str((const char *)&error_log[0]);

        throw std::runtime_error("Could not link program: " + error_log_str);
    }

    // detach shaders after successful link
    glDetachShader(program_id_, fragment_shader_id_);
    glDetachShader(program_id_, vertex_shader_id_);

    // we can then delete the shaders once we have the program
    glDeleteShader(fragment_shader_id_);
    glDeleteShader(vertex_shader_id_);
}

void GlslProgram::addAttribute(const std::string &attribute_name)
{
    glBindAttribLocation(program_id_, attribute_index_++,
                         attribute_name.c_str());
}

GLint GlslProgram::getUniformLocation(const std::string &uniform_name)
{
    GLint location = glGetUniformLocation(program_id_, uniform_name.c_str());
    if ((GLuint)location == GL_INVALID_INDEX) {
        throw std::runtime_error("'" + uniform_name + "' not found");
    }
    return location;
}

void GlslProgram::use()
{
    glUseProgram(program_id_);
    for (int i = 0; i < attribute_index_; ++i) {
        glEnableVertexAttribArray(i);
    }
}

void GlslProgram::unuse()
{
    for (int i = 0; i < attribute_index_; ++i) {
        glDisableVertexAttribArray(i);
    }
    glUseProgram(0);
}

void GlslProgram::defaultSetup()
{
    std::string vertexShader =
        "#version 130\n\nin vec2 vertex_position;\nin vec4 vertex_colour;\nin "
        "vec2 vertex_uv;\n\nout vec2 fragment_position;\nout vec4 "
        "fragment_colour;\nout vec2 fragment_uv;\n\nuniform mat4 P;\n\nvoid "
        "main()\n{\n    gl_Position.xy = (P*vec4(vertex_position, 0.0, "
        "1.0)).xy;\n    gl_Position.z = 0.0;\n    gl_Position.w = 1.0;\n\n    "
        "fragment_position = vertex_position;\n    fragment_colour = "
        "vertex_colour;\n    fragment_uv = vec2(vertex_uv.x, "
        "1-vertex_uv.y);\n\n}";

    std::string fragmentShader =
        "#version 130\n\nin vec2 fragment_position;\nin vec4 "
        "fragment_colour;\nin vec2 fragment_uv;\n\nout vec4 colour;\n\nuniform "
        "sampler2D texture_sampler;\n\nvoid main()\n{\n    vec4 texture_color "
        "= texture(texture_sampler, fragment_uv);\n\n    colour = "
        "texture_color;\n}";

    compileShaders(vertexShader, fragmentShader);
    addAttribute("vertex_position");
    addAttribute("vertex_colour");
    addAttribute("vertex_uv");

    linkShaders();
}

} // namespace yage
