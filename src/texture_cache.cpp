#include "image_loader.hpp"
#include "texture_cache.hpp"

TextureCache::TextureCache()
{}

TextureCache::~TextureCache()
{}

GlTexture TextureCache::getTexture(const std::string &texture_path)
{
    auto itr = texture_map_.find(texture_path);

    if(itr == texture_map_.end())
    {
	GlTexture new_texture = ImageLoader::loadPng(texture_path);
	texture_map_.insert(make_pair(texture_path, new_texture));
	return new_texture;
    }

    return itr->second;
}
