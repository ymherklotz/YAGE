/* ----------------------------------------------------------------------------
 * imageloader.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include "texture.h"

#include <string>

namespace yage
{

class ImageLoader
{
public:
    static Texture loadPng(const std::string &file_path);
    static Texture loadSpriteSheet(const std::string &file_path);
};

} // namespace yage

#endif
