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

#include <rapidjson/reader.h>
#include <yage/base/imageloader.h>

using namespace std;
using namespace rapidjson;
using namespace yage::details;

namespace yage
{

namespace details
{

bool SpriteSheetHandler::Null()
{
    return true;
}

bool SpriteSheetHandler::Bool(bool)
{
    return true;
}

bool SpriteSheetHandler::Int(int i)
{
    return handleNumber(i);
}

bool SpriteSheetHandler::Uint(unsigned u)
{
    return handleNumber(static_cast<int>(u));
}

bool SpriteSheetHandler::Int64(int64_t i)
{
    return handleNumber(static_cast<int>(i));
}

bool SpriteSheetHandler::Uint64(uint64_t u)
{
    return handleNumber(static_cast<int>(u));
}

bool SpriteSheetHandler::Double(double d)
{
    return handleNumber(static_cast<int>(d));
}

bool SpriteSheetHandler::String(const char *, SizeType, bool)
{
    return true;
}

bool SpriteSheetHandler::Key(const char *str, SizeType length, bool)
{
    current_key_ = string(str, length);
    return true;
}

bool SpriteSheetHandler::StartObject()
{
    depth_++;

    if (depth_ == 3) {
        current_image_ = current_key_;
    }

    return true;
}

bool SpriteSheetHandler::EndObject(SizeType)
{
    if (depth_ == 3) {
        map_[current_image_] = coord_;
    }
    depth_--;
    return true;
}

bool SpriteSheetHandler::StartArray()
{
    return true;
}

bool SpriteSheetHandler::EndArray(SizeType)
{
    return true;
}

SpriteMap SpriteSheetHandler::spriteMap() const
{
    return map_;
}

int SpriteSheetHandler::imageWidth() const
{
    return image_width_;
}

int SpriteSheetHandler::imageHeight() const
{
    return image_height_;
}

bool SpriteSheetHandler::handleNumber(int i)
{
    if (current_key_ == "width") {
        if (depth_ == 1) {
            image_width_ = i;
        } else {
            coord_.width = i;
        }
    } else if (current_key_ == "height") {
        if (depth_ == 1) {
            image_height_ = i;
        } else {
            coord_.height = i;
        }
    } else if (current_key_ == "x") {
        coord_.x = i;
    } else if (current_key_ == "y") {
        coord_.y = i;
    }
    return true;
}

} // namespace details

SpriteSheet::SpriteSheet(string pngFileName, string jsonFileName)
{
    string fileContents = fileContent(jsonFileName);

    SpriteSheetHandler ssHandler;
    Reader reader;
    StringStream ss(fileContents.c_str());
    reader.Parse(ss, ssHandler);

    fileLocations_ = ssHandler.spriteMap();
    texture_ = ImageLoader::loadPng(pngFileName);

    if (texture_.width != ssHandler.imageWidth())
        throw runtime_error("Texture width not equal: " +
                            to_string(texture_.width) +
                            " != " + to_string(ssHandler.imageWidth()));
    if (texture_.height != ssHandler.imageHeight())
        throw runtime_error(
            "Texture height not equal: " + to_string(texture_.height) +
            " != " + to_string(ssHandler.imageHeight()));
    assert(texture_.height == ssHandler.imageHeight());
}

string SpriteSheet::fileContent(string jsonFileName) const
{
    ifstream inputFile(jsonFileName);

    stringstream stream;
    stream << inputFile.rdbuf();

    return stream.str();
}

} // namespace yage
