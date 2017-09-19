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

    Coordinate(int x_i, int y_i, int width_i, int height_i)
        : x(x_i), y(y_i), width(width_i), height(height_i)
    {
    }
};

} // namespace details

class SpriteSheet
{
public:
    SpriteSheet(std::string pngFileName, std::string jsonFileName);

    void sprite(std::string spriteName) const;

private:
    Texture texture_;
    std::map<std::string, details::Coordinate> fileLocations_;
};

} // namespace yage

#endif
