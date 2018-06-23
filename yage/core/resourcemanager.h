/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: resourcemanager.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include "texturecache.h"

#include <string>

namespace yage
{

struct Texture;

class ResourceManager
{
private:
    static TextureCache texture_cache_;

public:
    static Texture getTexture(std::string const &texture_path, int x = 1,
                              int y = 1);
};

} // namespace yage
