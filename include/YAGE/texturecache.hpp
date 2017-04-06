#ifndef TEXTURE_CACHE_HPP
#define TEXTURE_CACHE_HPP

#include "texture.hpp"

#include <unordered_map>

namespace yage
{

class TextureCache
{
private:
    std::unordered_map<std::string, Texture> texture_map_;
public:
    TextureCache();
    ~TextureCache();

    Texture getTexture(const std::string &texture_path);
};
    
} // yage

#endif
