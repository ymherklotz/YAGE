/* ----------------------------------------------------------------------------
 * spritesheet.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "spritesheet.h"

#include <cassert>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include <rapidjson/document.h>
#include <yage/base/imageloader.h>

using namespace std;
using namespace rapidjson;
using namespace yage::details;

namespace yage
{

SpriteSheet::SpriteSheet(string pngFileName, string jsonFileName)
{
    string fileContents = fileContent(jsonFileName);
}

string SpriteSheet::fileContent(string jsonFileName) const
{
    ifstream inputFile(jsonFileName);

    stringstream stream;
    stream << inputFile.rdbuf();

    return stream.str();
}

SpriteMap SpriteSheet::parseJson(int &width, int &height, const string &jsonContent) const
{
    SpriteMap spriteMap;
    Document jsonAtlas;
    jsonAtlas.Parse(jsonContent.c_str());

    width = jsonAtlas["width"].GetInt();
    height = jsonAtlas["height"].GetInt();

    for (auto &texture : jsonAtlas["sprites"].GetObject()) {
        spriteMap[texture.name.GetString()] = Coordinate();
        for (auto &value : texture.value.GetObject()) {
            /// @todo add the coordinate to the map
        }
    }

    return spriteMap;
}

} // namespace yage
