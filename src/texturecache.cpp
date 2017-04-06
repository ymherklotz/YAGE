#include "imageloader.hpp"
#include "texturecache.hpp"

namespace yage
{

TextureCache::TextureCache()
{}

TextureCache::~TextureCache()
{}

Texture TextureCache::getTexture(const std::string &texture_path)
{
    auto itr = texture_map_.find(texture_path);

    if(itr == texture_map_.end())
    {
	Texture new_texture = ImageLoader::loadPng(texture_path);
	texture_map_.insert(make_pair(texture_path, new_texture));
	return new_texture;
    }

    return itr->second;
}
    
} // yage
