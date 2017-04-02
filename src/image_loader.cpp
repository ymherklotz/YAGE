#include "image_loader.hpp"
#include "io_manager.hpp"
#include "pico_png.hpp"

#include <stdexcept>

GlTexture ImageLoader::loadPng(const std::string &file_path)
{
    GlTexture texture = {};

    std::vector<unsigned char> in;
    std::vector<unsigned char> out;
    unsigned long width, height;

    if(!IoManager::readFileToBuffer(file_path, in))
	throw std::runtime_error("Failed to load '"+file_path+"' to buffer");

    int error_code = decodePNG(out, width, height, &in[0], in.size());
    if(error_code != 0)
	throw std::runtime_error("Failed to load '"+file_path+"' to png with error code"+std::to_string(error_code));

    glGenTextures(1, &texture.id);
    
    glBindTexture(GL_TEXTURE_2D, texture.id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &out[0]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);

    texture.width = (int)width;
    texture.height = (int)height;

    return texture;
}
