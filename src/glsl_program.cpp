#include "glsl_program.hpp"

#include <fstream>
#include <stdexcept>
#include <vector>

GlslProgram::GlslProgram()
{}

GlslProgram::~GlslProgram()
{
    // cleanup all the shaders and the program
    if(fragment_shader_id_ != 0)
	glDeleteShader(fragment_shader_id_);
    
    if(vertex_shader_id_ != 0)
	glDeleteShader(vertex_shader_id_);
    
    if(program_id_ != 0)
	glDeleteProgram(program_id_);
}

void GlslProgram::compileShader(const GLuint &shader, const std::string &file_path)
{
    // get a string with the input from the shader file
    std::ifstream file(file_path);
    if(!file.is_open())
	throw std::runtime_error("Failed to open '"+file_path+"'");

    std::string content = "";
    std::string line;

    while(std::getline(file, line))
	content+=line+"\n";
    file.close();

    // cast source to a c string to get the address of it and input it for compilation
    const GLchar *vertex_source = (const GLchar *)content.c_str();
    glShaderSource(shader, 1, &vertex_source, nullptr);
    glCompileShader(shader);

    // check if compilation was successful
    GLint is_compiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, (int *)&is_compiled);

    // if it isn't compiled throw exception to clean up
    if(is_compiled == GL_FALSE)
    {
	GLint max_length = 0;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &max_length);
 
	std::vector<GLchar> error_log(max_length);
	glGetShaderInfoLog(shader, max_length, &max_length, &error_log[0]);
	std::string error_log_str((const char *)&error_log[0]);
	
	throw std::runtime_error("Couldn't compile "+file_path+" : "+error_log_str);
    }
}

void GlslProgram::compileShaders(const std::string &vertex_shader_path, const std::string &fragment_shader_path)
{
    // create the program that will be run on GPU
    program_id_ = glCreateProgram();

    // create vertex shader
    vertex_shader_id_ = glCreateShader(GL_VERTEX_SHADER);
    if(vertex_shader_id_ == 0)
	throw std::runtime_error("Vertex shader failed to be created");

    // create fragment shader
    fragment_shader_id_ = glCreateShader(GL_FRAGMENT_SHADER);
    if(fragment_shader_id_ == 0)
	throw std::runtime_error("Fragment shader failed to be created");

    // compile the two shaders
    compileShader(vertex_shader_id_, vertex_shader_path);
    compileShader(fragment_shader_id_, fragment_shader_path);    
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
    if(is_linked == GL_FALSE)
    {
	GLint max_length = 0;
	glGetProgramiv(program_id_, GL_INFO_LOG_LENGTH, &max_length);

	std::vector<GLchar> error_log(max_length);
	glGetProgramInfoLog(program_id_, max_length, &max_length, &error_log[0]);

	std::string error_log_str((const char *)&error_log[0]);

	throw std::runtime_error("Could not link program : "+error_log_str);
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
    glBindAttribLocation(program_id_, attribute_index_++, attribute_name.c_str());
}

GLint GlslProgram::getUniformLocation(const std::string &uniform_name)
{
    GLint location = glGetUniformLocation(program_id_, uniform_name.c_str());
    if((GLuint)location == GL_INVALID_INDEX)
	throw std::runtime_error("'"+uniform_name+"' not found");
    return location;
}

void GlslProgram::use()
{
    glUseProgram(program_id_);
    for(int i = 0; i < attribute_index_; ++i)
	glEnableVertexAttribArray(i);
}

void GlslProgram::unuse()
{
    for(int i = 0; i < attribute_index_; ++i)
	glDisableVertexAttribArray(i);
    glUseProgram(0);
}
