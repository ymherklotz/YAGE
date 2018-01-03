#ifndef YAGE_CORE_DRAWABLE_H
#define YAGE_CORE_DRAWABLE_H

#include "spritebatch.h"

namespace yage
{

class Drawable
{
public:
    virtual void draw(SpriteBatch &sp) const = 0;
};

} // namespace yage

#endif
