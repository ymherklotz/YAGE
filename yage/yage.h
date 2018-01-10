/** ---------------------------------------------------------------------------
 * @file: yage.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_YAGE_H
#define YAGE_YAGE_H

/**
 * Core includes
 */
#include "core/camera.h"
#include "core/iomanager.h"
#include "core/logger.h"
#include "core/resourcemanager.h"
#include "core/spritesheet.h"
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
 * Physics implementation however, Box2D
 */
#include "physics/body.h"
#include "physics/particlebody.h"
#include "physics/rectanglecollider.h"
#include "physics/rigidbody.h"

/**
 * Rendering implementations for spritebatching and default shapes.
 */
#include "render/drawable.h"
#include "render/shader.h"
#include "render/spritebatch.h"

/**
 * Engine that includes a Entity Component System to organize the data and make
 * it more flexible and efficient.
 */
#include "engine/engine.h"

/**
 * Project namespace.
 *
 * Avoids collision as all the classes and global functions are wrapped in.
 */
namespace yage
{

/**
 *
 */
extern void glfwErrorCallback(int, const char *);

/**
 * Initializes YAGE.
 *
 * This is there to initialize GLFW, which is the current
 * window manager that is used with OpenGL.
 */
extern void init();

/**
 * Quit and cleanup YAGE.
 *
 * This also cleans up GLFW after it was initialized.
 */
extern void quit();

} // namespace yage

#endif
