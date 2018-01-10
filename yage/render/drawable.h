/** ---------------------------------------------------------------------------
 * @file: drawable.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_CORE_DRAWABLE_H
#define YAGE_CORE_DRAWABLE_H

#include "spritebatch.h"

namespace yage
{

class Drawable
{
public:
    virtual void draw(SpriteBatch &sp) = 0;
};

} // namespace yage

#endif
