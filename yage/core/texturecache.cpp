/* ----------------------------------------------------------------------------
 * texturecache.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include <yage/core/imageloader.h>
#include <yage/core/texturecache.h>

namespace yage
{

Texture TextureCache::getTexture(const std::string &texture_path)
{
    auto itr = texture_map_.find(texture_path);

    if (itr == texture_map_.end()) {
        Texture new_texture = ImageLoader::loadPng(texture_path);
        texture_map_.insert(make_pair(texture_path, new_texture));
        return new_texture;
    }

    return itr->second;
}

} // namespace yage
