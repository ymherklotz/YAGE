/** ---------------------------------------------------------------------------
 * @file: imageloader.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include <string>

namespace yage
{

class Texture;

class ImageLoader
{
public:
    static Texture loadPng(const std::string &file_path);
};

} // namespace yage

#endif
