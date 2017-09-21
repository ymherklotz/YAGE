/* ----------------------------------------------------------------------------
 * spritesheet.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_SPRITESHEET_H
#define YAGE_SPRITESHEET_H

#include "texture.h"

#include <rapidjson/reader.h>

#include <map>
#include <string>

namespace yage
{

namespace details
{

struct Coordinate {
    int x;
    int y;
    int width;
    int height;

    Coordinate() = default;

    Coordinate(int x_i, int y_i, int width_i, int height_i)
        : x(x_i), y(y_i), width(width_i), height(height_i)
    {
    }
};

typedef std::map<std::string, details::Coordinate> SpriteMap;

class SpriteSheetHandler
    : public rapidjson::BaseReaderHandler<rapidjson::UTF8<>, SpriteSheetHandler>
{
public:
    bool Null();
    bool Bool(bool b);
    bool Int(int i);
    bool Uint(unsigned u);
    bool Int64(int64_t i);
    bool Uint64(uint64_t u);
    bool Double(double d);
    bool String(const char *str, rapidjson::SizeType length, bool copy);

    bool Key(const char *str, rapidjson::SizeType length, bool copy);
    bool StartObject();
    bool EndObject(rapidjson::SizeType memberCount);
    bool StartArray();
    bool EndArray(rapidjson::SizeType memberCount);

    SpriteMap spriteMap() const;

private:
    std::string current_key_;
    int depth_;
    SpriteMap map_;

    bool handleNumber(int i);
};

} // namespace details

class SpriteSheet
{
public:
    SpriteSheet(std::string pngFileName, std::string jsonFileName);

    void sprite(std::string spriteName) const;

private:
    Texture texture_;
    details::SpriteMap fileLocations_;
};

} // namespace yage

#endif
