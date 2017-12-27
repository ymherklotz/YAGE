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
