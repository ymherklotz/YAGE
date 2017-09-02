/* ----------------------------------------------------------------------------
 * resourcemanager.hpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include "texture.hpp"
#include "texturecache.hpp"

#include <string>

namespace yage
{

class ResourceManager
{
private:
    static TextureCache texture_cache_;

public:
    static Texture getTexture(const std::string &texture_path);
};

} // namespace yage

#endif
