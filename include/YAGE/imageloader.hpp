/* ----------------------------------------------------------------------------
 * imageloader.hpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

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
