/* ----------------------------------------------------------------------------
 * resourcemanager.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

/* ----------------------------------------------------------------------------
 * resourcemanager.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "texture.h"
#include "texturecache.h"

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
