/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: yage.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

/**
 * Core includes
 */
#include "core/camera.h"
#include "core/core.h"
#include "core/iomanager.h"
#include "core/logger.h"
#include "core/resourcemanager.h"
#include "core/window.h"

/**
 * Data structues useful for the game engine and games developed by it
 */
#include "data/input.h"
#include "data/texture.h"
#include "data/vertex.h"

/**
 * Math templated implementation of matrices and operations on them.
 */
#include "math/matrix.h"

/**
 * Physics implementation however
 */
// #include "physics/body.h"
// #include "physics/particlebody.h"
// #include "physics/rectanglecollider.h"
// #include "physics/rigidbody.h"

/**
 * Rendering implementations for spritebatching and default shapes.
 */
#include "render/shader.h"
#include "render/spritebatch.h"
