/* ----------------------------------------------------------------------------
 * spritesheet.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "spritesheet.h"

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

bool SpriteSheetHandler::String(const char *, rapidjson::SizeType, bool)
{
    return true;
}

bool SpriteSheetHandler::Key(const char *str, rapidjson::SizeType length, bool)
{
    current_key_ = std::string(str, length);
    return true;
}

bool SpriteSheetHandler::StartObject()
{
    if(depth_ == 2) {
        map_[current_key_] = Coordinate();
    }

    depth_++;
    return true;
}

bool SpriteSheetHandler::EndObject(rapidjson::SizeType)
{
    depth_--;
    return true;
}

bool SpriteSheetHandler::StartArray()
{
    return true;
}

bool SpriteSheetHandler::EndArray(rapidjson::SizeType)
{
    return true;
}

bool SpriteSheetHandler::handleNumber(int i)
{
    if(current_key_ == "width") {
        if(depth_ == 1) {
            
        }
    }
    return true;
}

} // namespace details

} // namespace yage
