/* ----------------------------------------------------------------------------
 * spritesheet.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

/** @file
 */

#include "spritesheet.h"

#include <cassert>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include <rapidjson/document.h>
#include <yage/core/imageloader.h>

using namespace std;
using namespace rapidjson;
using namespace yage::details;

namespace yage
{

SpriteSheet::SpriteSheet(string pngFileName, string jsonFileName)
{
    int jsonWidth, jsonHeight;
    fileLocations_ =
        parseJson(jsonWidth, jsonHeight, fileContent(jsonFileName));
    texture_ = ImageLoader::loadPng(pngFileName);

    if (texture_.width != jsonWidth)
        throw runtime_error("JSON width does not match texture width");
    if (texture_.height != jsonHeight) 
        throw runtime_error("JSON height does not match texture height");
}

string SpriteSheet::fileContent(string jsonFileName) const
{
    ifstream inputFile(jsonFileName);

    stringstream stream;
    stream << inputFile.rdbuf();

    return stream.str();
}

SpriteMap SpriteSheet::parseJson(int &width, int &height,
                                 string jsonContent) const
{
    SpriteMap spriteMap;
    Document jsonAtlas;
    jsonAtlas.Parse(jsonContent.c_str());

    width = jsonAtlas["width"].GetInt();
    height = jsonAtlas["height"].GetInt();

    for (auto &texture : jsonAtlas["sprites"].GetObject()) {
        Coordinate coord;
        for (auto &value : texture.value.GetObject()) {
            string keyName{value.value.GetString()};
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
                throw runtime_error("JSON key incorrect: " + keyName);
            }
        }
        spriteMap[texture.name.GetString()] = coord;
    }

    return spriteMap;
}

} // namespace yage
