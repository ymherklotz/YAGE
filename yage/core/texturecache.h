/** ---------------------------------------------------------------------------
 * @file: texturecache.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef TEXTURE_CACHE_H
#define TEXTURE_CACHE_H

#include "texture.h"

#include <unordered_map>

namespace yage
{

class TextureCache
{
private:
    std::unordered_map<std::string, Texture> texture_map_;

public:
    TextureCache() = default;

    Texture getTexture(const std::string &texture_path);
    Texture getTextureFromSpriteSheet();
};

} // namespace yage

#endif
