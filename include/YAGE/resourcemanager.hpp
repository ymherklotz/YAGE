#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include "gltexture.hpp"
#include "texturecache.hpp"

#include <string>

namespace yage
{

class ResourceManager
{
private:
    static TextureCache texture_cache_;
public:
    static GlTexture getTexture(const std::string &texture_path);
};
    
} // yage

#endif
