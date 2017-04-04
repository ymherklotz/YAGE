#ifndef IMAGE_LOADER_HPP
#define IMAGE_LOADER_HPP

#include "gltexture.hpp"

#include <string>

namespace yage
{

class ImageLoader
{
public:
    static GlTexture loadPng(const std::string &file_path);
};
    
} // yage

#endif
