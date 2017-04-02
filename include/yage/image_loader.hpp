#ifndef IMAGE_LOADER_HPP
#define IMAGE_LOADER_HPP

#include "gl_texture.hpp"

#include <string>

class ImageLoader
{
public:
    static GlTexture loadPng(const std::string &file_path);
};


#endif
