/* ----------------------------------------------------------------------------
 * rigidbody.hpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_RIGID_BODY_HPP
#define YAGE_RIGID_BODY_HPP

#include <glm/glm.hpp>

#include "particlebody.hpp"

namespace yage
{

class RigidBody : public ParticleBody
{
public:
	RigidBody(const Vector2d &position=Vector2d(0, 0),
	          double mass=1,
 	          const Vector2d &velocity=Vector2d(0, 0),
	          bool gravity=true);
};

} // yage

#endif
