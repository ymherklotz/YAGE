/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: imageloader.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include <string>

namespace yage
{

class Texture;

class ImageLoader
{
public:
    static Texture loadPng(std::string const &file_path);
};

} // namespace yage
