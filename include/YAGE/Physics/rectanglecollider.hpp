#ifndef YAGE_RECTANGLE_COLLIDER_HPP
#define YAGE_RECTANGLE_COLLIDER_HPP

#include "Physics/collider.hpp"

#include <glm/glm.hpp>

namespace yage
{

class RectangleCollider : public Collider
{
public:
	RectangleCollider(const glm::vec2 &position, const glm::vec2 &size);

	virtual bool collides(const Collider &collider) const;
	virtual bool inside(const glm::vec2 &point) const;
};

} // yage

#endif
