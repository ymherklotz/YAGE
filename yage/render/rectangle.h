/** ---------------------------------------------------------------------------
 * @file: rectangle.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_RENDER_RECTANGLE_H
#define YAGE_RENDER_RECTANGLE_H

#include "shape.h"

#include <glm/glm.hpp>

namespace yage
{

class Rectangle : public Shape
{
public:
    Rectangle(glm::vec4 position);
    virtual void render() const;

private:
    glm::vec4 position_;
};

} // namespace yage

#endif
