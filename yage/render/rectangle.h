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
