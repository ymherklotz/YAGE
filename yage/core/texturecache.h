/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: texturecache.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include "../data/texture.h"

#include <unordered_map>

namespace yage
{

class TextureCache
{
private:
    std::unordered_map<std::string, Texture> texture_map_;

public:
    TextureCache() = default;

    Texture getTexture(std::string const &texture_path, int x = 1, int y = 1);
};

} // namespace yage
