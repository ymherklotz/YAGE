/** ---------------------------------------------------------------------------
 * @file: spritesheet.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

/// @file

#ifndef YAGE_SPRITESHEET_H
#define YAGE_SPRITESHEET_H

/** @todo think of removing this, by, for example, using a pointer
 * This could be more efficient when copying the texture out of the
 * spritesheet.
 */
#include "../data/texture.h"

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

} // namespace details

class SpriteSheet
{
public:
    SpriteSheet(std::string pngFileName, std::string jsonFileName);

    void sprite(std::string spriteName) const;
    std::string fileContent(std::string jsonFileName) const;

private:
    Texture texture_;
    details::SpriteMap fileLocations_;

    details::SpriteMap parseJson(int &width, int &height,
                                 std::string jsonContent) const;
};

} // namespace yage

#endif
