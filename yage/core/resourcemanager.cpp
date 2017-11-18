/* ----------------------------------------------------------------------------
 * resourcemanager.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "resourcemanager.h"

namespace yage
{

TextureCache ResourceManager::texture_cache_;

Texture ResourceManager::getTexture(const std::string &texture_path)
{
    return texture_cache_.getTexture(texture_path);
}

} // namespace yage