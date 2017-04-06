#include "resourcemanager.hpp"

namespace yage
{

TextureCache ResourceManager::texture_cache_;

Texture ResourceManager::getTexture(const std::string &texture_path)
{
    return texture_cache_.getTexture(texture_path);
}
    
} // yage
