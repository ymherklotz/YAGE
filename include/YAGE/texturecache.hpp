#ifndef TEXTURE_CACHE_HPP
#define TEXTURE_CACHE_HPP

#include "gltexture.hpp"

#include <unordered_map>

namespace yage
{

class TextureCache
{
private:
    std::unordered_map<std::string, GlTexture> texture_map_;
public:
    TextureCache();
    ~TextureCache();

    GlTexture getTexture(const std::string &texture_path);
};
    
} // yage

#endif
