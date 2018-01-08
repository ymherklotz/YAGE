/** ---------------------------------------------------------------------------
 * @file: shape.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_RENDER_SHAPE_H
#define YAGE_RENDER_SHAPE_H

#include "drawable.h"

namespace yage
{

class Shape : public Drawable
{
public:
    virtual void render() const;
};

} // namespace yage

#endif
