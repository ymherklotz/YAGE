#ifndef IMAGE_LOADER_HPP
#define IMAGE_LOADER_HPP

#include "texture.hpp"

#include <string>

namespace yage
{

class ImageLoader
{
public:
    static Texture loadPng(const std::string &file_path);
};
    
} // yage

#endif
