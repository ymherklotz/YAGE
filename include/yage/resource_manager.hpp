#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include "gl_texture.hpp"
#include "texture_cache.hpp"

#include <string>

class ResourceManager
{
private:
    static TextureCache texture_cache_;
public:
    static GlTexture getTexture(const std::string &texture_path);
};


#endif
