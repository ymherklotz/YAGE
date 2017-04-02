#include "resource_manager.hpp"

TextureCache ResourceManager::texture_cache_;

GlTexture ResourceManager::getTexture(const std::string &texture_path)
{
    return texture_cache_.getTexture(texture_path);
}
