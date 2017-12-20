/* ----------------------------------------------------------------------------
 * spritesheet.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

/// @file

#include "spritesheet.h"

#include <rapidjson/document.h>
#include <yage/core/imageloader.h>

#include <cassert>
#include <fstream>
#include <sstream>
#include <stdexcept>

using rapidjson::Document;
using yage::details::Coordinate;
using yage::details::SpriteMap;

namespace yage
{

SpriteSheet::SpriteSheet(std::string pngFileName, std::string jsonFileName)
{
    int jsonWidth, jsonHeight;
    fileLocations_ =
        parseJson(jsonWidth, jsonHeight, fileContent(jsonFileName));
    texture_ = ImageLoader::loadPng(pngFileName);

    if (texture_.width != jsonWidth)
        throw std::runtime_error("JSON width does not match texture width");
    if (texture_.height != jsonHeight)
        throw std::runtime_error("JSON height does not match texture height");
}

std::string SpriteSheet::fileContent(std::string jsonFileName) const
{
    std::ifstream inputFile(jsonFileName);

    std::stringstream stream;
    stream << inputFile.rdbuf();

    return stream.str();
}

SpriteMap SpriteSheet::parseJson(int &width, int &height,
                                 std::string jsonContent) const
{
    SpriteMap spriteMap;
    Document jsonAtlas;
    jsonAtlas.Parse(jsonContent.c_str());

    width = jsonAtlas["width"].GetInt();
    height = jsonAtlas["height"].GetInt();

    for (auto &texture : jsonAtlas["sprites"].GetObject()) {
        Coordinate coord;
        for (auto &value : texture.value.GetObject()) {
            std::string keyName{value.value.GetString()};
            int keyValue{value.value.GetInt()};
            if (keyName == "x") {
                coord.x = keyValue;
            } else if (keyName == "y") {
                coord.y = keyValue;
            } else if (keyName == "width") {
                coord.width = keyValue;
            } else if (keyName == "height") {
                coord.height = keyValue;
            } else {
                throw std::runtime_error("JSON key incorrect: " + keyName);
            }
        }
        spriteMap[texture.name.GetString()] = coord;
    }

    return spriteMap;
}

} // namespace yage
